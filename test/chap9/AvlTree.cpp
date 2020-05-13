//
// Created by hsh on 2020/5/11.
//

#include "AvlTree.h"
#include <iostream>
using namespace std;


template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::insert(const set<KEY,OTHER> &x, avlnode *& t){
    if (t== nullptr ) t=new avlnode (x, nullptr , nullptr);
    else if (x.key<t->data.key) {
        insert(x,t->left);
        if (height(t->left)-height(t->right) ==2 ) {
            if (x.key < t->left->data.key) LL(t);
            else LR(t);
        }
    }
    else if (x.key > t->data.key) {
        insert(x,t->right);
        if (height(t->left)-height(t->right) ==2 ) {
            if (x.key < t->left->data.key) RL(t);
            else RR(t);
        }
    }

    t->height=max(height(t->left),height(t->right))+1;
}


template <class KEY, class OTHER>
bool AvlTree<KEY,OTHER>::remove(const KEY & x, avlnode*&t){
    if (t== nullptr) retun true;
    if (x == t->data.key) {                               // 在本树上删除
        if (t->left == nullptr || t->right == nullptr) {   /*只有一个儿子*/
            avlnode *oldnode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldnode;
            return false;
        } else {                                                 /*两个儿子*/
            avlnode *tem = t->right;
            while (tem->left != nullptr) tem = tem->left;
            t->data = tem->data;
            if (remove(tem->data.key, t->right)) return false;
            return adjust(t, 1);
        }
    }
    if (x < t->data.key) {
        if (remove(x, t->left)) return true;
        return adjust(t, 0);
    } else if (x < t->data.key) {
        if (remove(x, t->right)) return true;
        return adjust(t, 1);
    }
}



template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::makeEmpty(avlnode * t){
    if (t==nullptr) return ;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}



template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::LL (avlnode* & t){
    avlnode* t1=t->left;

    t->left=t1->right;
    t1->right=t;

    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t1->left),height(t1->right))+1;

    t=t1;  // important  because all operation is based on the paracondition ---- "&"
}


template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::LR (avlnode* & t){
    RR(t->left);
    LL(t);
}


template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::RR (avlnode* & t){
    avlnode *t1=t->right;
    t->right-t1->left;
    t1->left=t;

    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t1->left),height(t1->right))+1;
    t=t1;
}


template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::RL (avlnode* & t){
    LL(t->right);
    RR(t);
}


template <class KEY, class OTHER>
bool AvlTree<KEY,OTHER>::adjust(avlnode *&t, int subTree){
    if (subtree){
        if (height(t->left)-height(t->right)==1) return true;
        if (height(t->left)==height(t->right))  {--t->height; return false;}
        if (height(t->left->right) > height(t->left->left)){ LR(t); return false;}
        {
            LL(t);
            if (height((t->right)) == height((t->left ))  )  return false ;else return true;
        }
    }
    else {
        if (height(t->left)-height(t->right)==1) return true;
        if (height(t->left)==height(t->right))  {--t->height; return false;}
        if (height(t->right->left) > height(t->right->right)){ RL(t); return false;}
        {
            RR(t);
            if (height((t->right)) == height((t->left ))  )  return false ;else return true;
        }
    }
    }

}


template <class KEY, class OTHER>
set<KEY,OTHER> *AvlTree<KEY,OTHER>::find(const KEY &x) const{
    avlnode *t=root;

    while (t!= nullptr && t->data.key ==x){
        if (t->data.key > x) t=t->right;
        else t=t->left;
    }

    if (t==nullptr) return nullptr;
    else return &(t->data);  // todo  remember to modify it if it's different with teacher's code
}


template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::insert(const set<KEY,OTHER> &x){
    insert(x,root);
}


template <class KEY, class OTHER>
void AvlTree<KEY,OTHER>::remove(const KEY &x ){
    remove(x,root);
}
