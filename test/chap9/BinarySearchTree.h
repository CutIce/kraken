//
// Created by hsh on 2020/5/11.
//
#ifndef CLIONCODE_BINARYSEARCHTREE_H
#define CLIONCODE_BINARYSEARCHTREE_H

#include "set.h"
template <class key,class other>
class BinarySearchTree {
private:
    struct BinaryNode{
        set<key,other> data;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const set<key,other> &thedata, BinaryNode *l= nullptr,BinaryNode *r= nullptr): data(thedata),left(l),right(r){}
    };

    BinaryNode *root;

    void find(const set<key,other> &x, BinaryNode * &t);
    void remove(const key &x, BinaryNode* & t);
    set<key,other> * find(const key &x,BinaryNode *&t) const;
    void makeEmpty(BinaryNode *t);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    set<key,other> * find(const key &x) const;
    void insert(const set<key,other> &x);
    void remove(const key &x);
};


#endif //CLIONCODE_BINARYSEARCHTREE_H

