#ifndef BTREE_HPP
# define BTREE_HPP

#include "Bnode.hpp"

template <typename T>
class Tree
 {
private:
    BNode<T> *root;

    void insert_to_node(T key, BNode<T> *node);
    void sort(BNode<T> *node);
    void restruct(BNode<T> *node);
    void deletenode(BNode<T> *node);
    bool searchKey(T key, BNode<T> *node);	
    void remove(T key, BNode<T> *node);
    void removeFromNode(T key, BNode<T> *node);
    void removeLeaf(T key, BNode<T> *node);
    void lconnect(BNode<T> *node, BNode<T> *othernode);
    void rconnect(BNode<T> *node, BNode<T> *othernode);
    void repair(BNode<T> *node);
	void print_b_tree(BNode<T> *a, int level);

public:
    Tree();
    ~Tree();
	void Print();
    void insert(T key);
    bool search(T key);
    void remove(T key);
};

#endif