//
// Created by hsh on 2020/4/22.
//

#ifndef HOMEWORK4_BBINARYTREE_H
#define HOMEWORK4_BINARYTREE_H
#include <string>
using namespace std;
class binaryTree {
private:
    struct node{
        int data;
        int leftval;
        int rightval;
        int parentval;
        node(){leftval= -1;rightval= -1;parentval= -1;}
        node(int d,int l =-1,int r=-1,int p=-1):data(d),leftval(l),rightval(r),parentval(p){};
    };
    int size;
    node *elem;

    string preOrder(int root);
    string midOrder(int root);
    string postOrder(int root);

    int find(int d);

public:
    binaryTree(){size=0;elem= nullptr;};
    ~binaryTree();
    void createTree(int n);
    string preOrder(){return preOrder(1);}
    string midOrder(){return midOrder(1);}
    string postOrder(){return postOrder(1);}
    void print();
};

#endif //HOMEWORK4_SEQBINARYTREE_H
