//
// Created by hsh on 2020/5/11.
//

#ifndef TEST_REDBLACKTREE_H
#define TEST_REDBLACKTREE_H

template <class KEY,class OTHER>
struct set{
    KEY key;
    OTHER other;
};

template <class KEY,class OTHER>
class RedBlackTree {

    enum colourT {
        RED, BLACK
    };

    struct redblacknode {
        set<KEY, OTHER> data;
        redblacknode *left;
        redblacknode *right;
        colourT colour;

        redblacknode(const set<KEY, OTHER> &element, redblacknode *lt = nullptr, redblacknode *rt = nullptr,
                     colourT h = RED)
                : data(element), left(lt), right(rt), colour(h) {};
    };

    redblacknode *root;

    void makeEmpty(redblacknode *&t);

    void insertAdjust(redblacknode *gp, redblacknode *p, redblacknode *t);

    void removeAdjust(redblacknode *&p, redblacknode *&c, redblacknode *&t, KEY &del);

    void LL(redblacknode *gp);

    void LR(redblacknode *gp);

    void LR(redblacknode *gp);

    void RR(redblacknode *gp);

}
#endif //TEST_REDBLACKTREE_H
