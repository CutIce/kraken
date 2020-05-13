//
// Created by hsh on 2020/5/11.
//
#include "BinarySearchTree.h"

template <class key,class other>
void BinarySearchTree<key,other>::find(const set<key,other> &x, BinaryNode * &t){
    if (t== nullptr) return nullptr;

}


template <class key,class other>
void BinarySearchTree<key,other>::remove(const key &x, BinaryNode* & t);


template <class key,class other>
set<key,other> * BinarySearchTree<key,other>::find(const key &x,BinaryNode *&t) const;


template <class key,class other>
void BinarySearchTree<key,other>::makeEmpty(BinaryNode *t);



template <class key,class other>
BinarySearchTree<key,other>::BinarySearchTree();


template <class key,class other>
BinarySearchTree<key,other>::~BinarySearchTree();


template <class key,class other>
set<key,other> * BinarySearchTree<key,other>::find(const key &x) const{
    return find(key,root);
}


template <class key,class other>
void BinarySearchTree<key,other>::insert(const set<key,other> &x);


template <class key,class other>
void BinarySearchTree<key,other>::remove(const key &x);