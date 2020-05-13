//
// Created by hsh on 2020/5/11.
//

#ifndef TEST_AVLTREE_H
#define TEST_AVLTREE_H

template <class KEY,class OTHER>
struct set{
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class AvlTree{

private:
    struct avlnode{
        set<KEY,OTHER> data;
        avlnode *left;
        avl *right;
        int height;

        avlnode(const set<KET,OTHER> & element, avlnode *;t, avlnode *rt,int h=1): data(element),left(lt), right(rt),height(h){}
    };

    avlnode * root;

    void insert(const set<KEY,OTHER> &x, avlnode *& t);
    bool remove(const KEY & x, avlnode*&t);
    void makeEmpty(avlnode * t);
    int height(alvnode *t)const {return t== nullptr ? 0:t->height;}
    void LL (avlnode* & t);
    void LR (avlnode* & t);
    void RR (avlnode* & t);
    void RL (avlnode* & t);
    int max(int a, int b) {return a>b ? a:b;}
    bool adjust(avlnode *&t, int subTree);

public:

    AvlTree () {root= nullptr;}
    ~AvlTree() {makeEmpty(root);}
    set<KEY,OTHER> *find(const KEY &x) const;
    void insert(const set<KEY,OTHER> &x);
    void remove(const KEY &x );
};


#endif //TEST_AVLTREE_H
