#ifndef CLIONCODE_BINARYTREE_H
#define CLIONCODE_BINARYTREE_H
#include <string>
#include <sstream>
using namespace std;

string int2string(int n){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;}

template<class T>
class binaryTree {
    friend string int2string(int n);
private:
    struct node{
        node *left,*right;
        T data;
        node() : left(nullptr),right(nullptr){};
        node(T da,node *l=nullptr,node *r=nullptr):left(l),right(r),data(da){};
    };
    node * root;

    node * find(T x, node * t) const {
        node *tem;
        if (t==nullptr) return nullptr;
        if (t->data==x) return t;
        if (tem=find(x,t->left)) return tem;
        else return find(x,t->right);
    }
    void clear(node *&t);
    string preOrder(node *t) const;
    string midOrder(node *t) const;
    string postOrder(node *t) const;
public:
    binaryTree():root(nullptr){}
    binaryTree(T da){root=new node(da);}
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T falg) const;
    T lchild(T x,T flag) const;
    T rchild(T x,T flag) const;
    void delleft(T x);
    void delright(T x);
    string preOrder() const;
    string midOrder() const;
    string postOrder() const;
    void levelOrder() const;
    void createTree();
    T parent(T x,T flag) const {return flag;}
};

template<class elemType>
class queue {
private:
    struct node{
        elemType data;
        node (const elemType&x,node *n=nullptr){data=x,next=n;};
        node *next;
        node():next(nullptr){};
        ~node(){};
    };
    node *front,*rear;
public:
    queue();
    ~queue();
    bool isEmpty() const;
    void enQueue(const elemType&x);
    elemType deQueue();
    elemType getHead() const;
};


#endif
