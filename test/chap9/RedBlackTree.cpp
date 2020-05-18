//
// Created by hsh on 2020/5/11.
//
#include "RedBlackTree.h"


template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::makeEmpty(redblacknode *&t){
    /*if (!t) return ;                // this is the way of para----without &   just like codes in BinarySearchTree  : makeEmpty(BinaryTreenode *t )
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;*/

    if (!t) return ;
    makeEmpty(t->left);
    makeEmpty(t->right);
    t= nullptr;
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::insertAdjust(redblacknode *gp, redblacknode *p, redblacknode *t){
    if (p->colour ) return;
    if (p==root) {
        p->colour =BLACK;
        return;
    }
    if (gp->left==p){
        if (p->left==t) LL(gp);else LR(gp);
        else if (p->right == t) RR(gp); else RL(gp);
    }
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::removeAdjust(redblacknode *&p, redblacknode *&c, redblacknode *&t, KEY &del){
    if (c->colour ==RED) return;
    if (c==root)
        if (c->left && c->right && c->right->colour == c->left->colour) {
            c->colour =RED;
            c->left->colour=c->right->colour=BLACK;
            return ;
        }

    if ( (c->left && c->left->colour || c->left== nullptr )  && (c->right && c->right->colour || c->right== nullptr)) {         // 如果c的左右子 t的左右子 都是黑的 // 枚举里面设置BLACK为1
        if ((t->left && t->left->colour || t->left == nullptr) &&
            (t->right && t->right->colour || t->right == nullptr)) {
            p->colour = BLACK;
            t->colour = c->colour = RED;
        } else {
            if (p->left == t) {
                if (t->left && t->left->colour == RED) {
                    t->left->colour = BLACK;
                    LL(p);
                    p = t;
                } else {
                    LR(p);
                    p = p->right;
                    p->colour = BLACK;
                }
                else if (t->right && t->right->colour == RED) {
                    t->right->colour = BLACK;
                    RR(p);
                    p = t;
                } else {
                    RL(p);
                    p = p->left;
                    p->colour = BLACK;
                }
                c->colour = RED;
            }
        }
        else {
            if (c->data.key == del) {
                if (c->left && c->right) {
                    LL(c);
                    c = c->right;
                }
                return;
            }
            if (c->left) {
                LL(c);
                p = c;
                c = c->right;
            } else {
                RR(c);
                p = c;
                c = c->left;
            }
        }
            else {
                p = c;
                c = (del < p->data.key ? p->left : p->right);
                if (c->colour == BLACK) {
                    if (t == p->right) RR(p); else LL(p);
                    p = t;
                    t = (c == p->left ? p->right : p->left);
                    removeAdjust(p, c, t, del);
                }
        }
    }
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::LL(redblacknode *gp){
    redblacknode *p=gp->left,*t=p->left;
    redblacknode tem=*gp;
    gp->data=p->data;
    gp->left=t;
    gp->right=p;
    p->data=tem.data;
    p->left=p->right;
    p->right=tem.right;
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::LR(redblacknode *gp){
    redblacknode *p=gp->left,*t=p->right;
    redblacknode tem=*gp;
    gp->data=t->data;
    p->right=t->left;
    t->left=t->right;
    t->right=gp->right;
    gp->right=t;
    t->data=tem.data;
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::LR(redblacknode *gp){
    redblacknode tem=*gp;
    redblacknode *p=gp->right,*t=p->right;
    gp->data=p->data;
    gp->right=p->right;
    p->right=p->left;
    p->data=tem.data;
    p->left=tem->left;
    gp->left=p;
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::RR(redblacknode *gp){
    redblacknode tem=*gp;
    redblacknode *p=gp->right.*t=p->left;
    gp->data=t->data;
    gp->left=t;
    p->left=t->right;
    t->data=tem.data;
    t->right=t->left;
    t->left=tem.left;
}



template <class KEY,class OTHER>
set<KEY,OTHER> * RedBlackTree<KEY,OTHER>::find(const KEY &x){
    redblacknode *t=root;

    while (t!= nullptr){
        if (t->data.key == x) return &(t->data);
        else if (t->data.key < x) t=t->left;
        else t=t->right;
    }
    return nullptr;
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::insert(const set<KEY,OTHER> &x){
    redblacknode *t,*parent,*grand;

    if (!root) {
        root=new redblacknode (x, nullptr, nullptr,BLACK);
        return ;
    }

    parent=grand=t=root;

    while (true){
        if (t){
            if (t->left && t->left->colour==RED && t->right && t->right->colour==RED){
                t->left->colour=BLACK;
                t->right->colour=BLACK;
                t->colour=RED;
                insertAdjust(grand,parent,t);
            }
            grand=parent;
            parent=t;
            t=(t->data.key>x.key ? t->left:t->right);
        }
        else {
            t=new redblacknode(x);
            if (x.key<parent->data.key) parent->left=t;
            else parent->right=t;
            insertAdjust(grand,parent,t);
            root->colour=BLACK;
            return ;
        }
    }
}



template <class KEY,class OTHER>
void RedBlackTree<KEY,OTHER>::remove(const KEY &x){
    KEY del=x;
    redblacknode *t,*p,*c;

    if (root== nullptr) return ;
    if (root->data.key ==x && root->left== nullptr &&root->right== nullptr){
        delete root;
        root= nullptr;
        return;
    }


    p=c=t=root;

    while (true){
        removeAdjust(p,c,t,del);
        if (c->data.key ==del && c->left && c->right){
            redblacknode* tmp=c->right;
            while (tmp->left) tmp=tmp->left;
            del=tmp->data.key;
            p=c;
            c=c->right;
            t=p->left;
            continue;
        }

        if (c->data.key == del){
            delete c;
            if (p->left == c ) p->left= nullptr; else p->right = nullptr;
            root->colour=BLACK;
            return ;
        }
        p=c;
        c=(del<p->data.key ? p->left : p->right);
        t=(c==p->left ? p->right :p->left);
    }
}