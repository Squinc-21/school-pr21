# -*- coding: utf-8 -*-
"""
Created on Mon Mar  2 21:55:28 2020

@author: User
"""
from time import time
import hashlib
import json
from uuid import uuid4
import flask
from urllib.parse import urlparse

class Blockchain(object):
    def __init__(self):
        self.chain = []
        self.current_transactions = []
        self.new_block(proof=3217, previous_hash=100)
        self.nodes = set()

    def new_block(self, proof, previous_hash=None):
        # Создает новый блок и вносит его в цепь
        block = {
                'index': len(self.chain) + 1,
                'timestamp': time(),
                'transactions': self.current_transactions,
                'proof': proof,
                'previous_hash' : previous_hash or self.hash(self.chain[-1]),
                }
        self.current_transactions = []
        self.chain.append(block)
        return block

    def new_transaction(self, sender, recipient, amount):
        # Вносит новую транзакцию в список транзакций
        self.current_transactions.append({
                "sender": sender,
                "recipient": recipient,
                "amount": amount,
                })
        return self.last_block['index'] + 1

    def proof_of_work(self, last_proof):
        proof = 0
        while self.valid_proof(last_proof, proof) is False:
            proof += 1
        return proof

    def register_node(self, adress):
        url_parsed = urlparse(adress)
        self.nodes.add(url_parsed.netlock())

    def valid_chain(self, chain):
        last_block = chain[0]
        cur_id = 1
        while cur_id < len(chain):
            block = chain[cur_id]
            if block['previous_hash'] != self.hash(last_block):
                return False
            if not self.valid_proof(last_block["proof"], block["proof"]):
                return False
            last_block = block
            cur_id += 1
        return True

    def resolve_conflicts(self):
        neighbours = self.nodes
        new_chain = None
        max_length = len(self.chain)

        for node in neighbours:
            response = flask.request.get(f"http://{node}/chain")
            if response.status_code == 200:
                length = response.json()["length"]
                chain = response.json()["chain"]
                if self.valid_chain(chain) and length > max_length:
                    max_length = length
                    new_chain = chain

        if new_chain:
            self.chain = new_chain
            return True
        return False

    @staticmethod
    def valid_proof(last_proof, proof):
        new = f'{last_proof}*{proof}'.encode()
        new_hash = hashlib.sha256(new).hexdigest()
        return new_hash[:3] == '000'

    @staticmethod
    def hash(block):
        block_string = json.dumps(block, sort_keys=True).encode()
        return hashlib.sha256(block_string).hexdigest()

    @property
    def last_block(self):
        return self.chain[-1]


app = flask.Flask(__name__)

node_identifier = str(uuid4()).replace('-', '')
blockchain = Blockchain()

@app.route('/mine', methods=['GET'])
def mine():
    print("Mining a new Block...")
    last_block = blockchain.last_block
    last_proof = last_block['proof']
    proof = blockchain.proof_of_work(last_proof)

    blockchain.new_transaction(
            sender="THE_CREATOR",
            recipient=node_identifier,
            amount=1)
    #prev_hash
    block = blockchain.new_block(proof)
    response = {
            "message":"New Block mined",
            "index":block['index'],
            "transactions":block["transactions"],
            "proof":block["proof"],
            "prev_hash":block["previous_hash"],
            }
    return flask.jsonify(response), 200


@app.route("/transactions/new", methods=['GET', 'POST'])
def new_transaction():
    print("Adding a new transaction...")
    values = flask.request.get_json(force=True)
    required = ["sender", "recipient", "amount"]

    if not all(k in values for k in required):
        return 'Missing values', 400

    index = blockchain.new_transaction(values['sender'],values['recipient'],values['amount'])
    response = {'message': f'Transaction will be added to Block {index}'}
    return flask.jsonify(response), 201


@app.route("/chain", methods=['GET'])
def full_chain():
    response = {
            'chain':blockchain.chain,
            'length':len(blockchain.chain),
            }
    return flask.jsonify(response), 200


@app.route("/nodes/register", methods=["POST"])
def register_nodes():
    values = flask.request.get_json()
    nodes = values.get("nodes")
    if not nodes:
        return "Error. Please, supply a valid list of nodes"
    for node in nodes:
        blockchain.register_node(node)
    response = {
            "message": "New node had been registered",
            "chain": blockchain.chain
            }
    return flask.jsonify(response), 201


@app.route("/nodes/resolve", methods=["GET"])
def consensus():
    replaced = blockchain.resolve_conflicts()
    if replaced:
        response = {
                "message": "Our chain was replaced",
                "new_chain": blockchain.chain,
                }
    else:
        response = {
                "message": "Our chain is correct",
                "chain": blockchain.chain,
                }
    return flask.jsonify(response), 200


if __name__ == '__main__':
    #app.debug = True
    app.run(host='0.0.0.0', port=5000)

