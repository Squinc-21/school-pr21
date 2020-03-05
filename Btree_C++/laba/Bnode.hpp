#ifndef BNODE_HPP
# define BNODE_HPP

const int t=2;

template <typename T1, typename T2>
struct Pair
{
	T1 key;
	T2 index;
};

template <typename T>
struct BNode 
{
    T keys[2*t];
    BNode *children[2*t+1];	
    BNode *parent;
    int count; //количество ключей
    int countSons; //количество сыновей
    bool leaf;
};

#endif