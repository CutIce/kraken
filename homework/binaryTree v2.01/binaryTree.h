//
// Created by hsh on 2020/4/22.
//

#ifndef HOMEWORK4_SEQBINARYTREE_H
#define HOMEWORK4_SEQBINARYTREE_H
#include <string>
using namespace std;


class binaryTree {
private:
    struct node{
        int data;
        int left;
        int right;
        int parent;
        node(){left= -1;right= -1;parent= -1;}
        node(int d,int l =-1,int r=-1,int p=-1):data(d),left(l),right(r),parent(p){};
    };
    int size;
    node *elem;
    string preOrder(int root);
    string midOrder(int root);
    string postOrder(int root);
    int find(int d,int root);
public:
    binaryTree(){size=0;elem= nullptr;};
    ~binaryTree();
    void createTree(int n);
    string preOrder();
    string midOrder();
    string postOrder();
    int getparent(int root){return elem[root].parent;}
};


#endif //HOMEWORK4_SEQBINARYTREE_H
