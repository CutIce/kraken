#include "binaryTree.h"
#include <iostream>
using namespace std;

template<class T>
void binaryTree<T>::clear(binaryTree<T>::node *&t){
    if (t==nullptr) return ;
    clear (t->left);
    clear (t->right);
    delete t;
    t=nullptr;
}

template<class T>
string binaryTree<T>::preOrder(node *t) const{
    string sl="",mid="",sr="",blank=" ";
    if (t==nullptr) return mid;
    mid=int2string(t->data);
    sl=preOrder(t->left);
    sr=preOrder(t->right);
    if (sl!="") {mid+=" ";}
    mid+=sl;
    if (sr!="") {mid+=" ";}
    mid+=sr;
    return mid;
}

template<class T>
string binaryTree<T>::midOrder(node *t) const{
    string sl="",mid="",sr="",blank=" ";
    if (t==nullptr) return mid;
    mid=int2string(t->data);
    sl=midOrder(t->left);
    sr=midOrder(t->right);
    if (sl!="") {sl+=blank;}
    sl+=mid;
    if (sr!="") {sl+=blank;}
    sl+=sr;
    return sl;
}

template<class T>
string binaryTree<T>::postOrder(node *t) const{
    string sl="",mid="",sr="",blank=" ";
    if (t==nullptr) return mid;
    mid=int2string(t->data);
    sl=postOrder(t->left);
    sr=postOrder(t->right);
    if (sl!=""&&sr!="") {sl+=" ";}
    sl+=sr;
    if (sl!="")  {sl+=blank;}
    sl+=mid;
    return sl;
}


// public :

template<class T>
binaryTree<T>::~binaryTree(){
    clear(root);
}

template<class T>
void binaryTree<T>:: clear(){
    clear(root);
}

template<class T>
bool binaryTree<T>:: isEmpty() const{
    return root==nullptr;
}

template<class T>
T binaryTree<T>::Root(T flag) const{
    if (root==nullptr) return flag;
    else return root->data;
}

template<class T>
T binaryTree<T>::lchild(T x,T flag) const{
    node *tem=find(x,root);
    if (tem==nullptr||tem->left==nullptr) return flag;
    return tem->left->data;
}

template<class T>
T binaryTree<T>::rchild(T x,T flag) const{
    node *tem=find(x,root);
    if (tem==nullptr||tem->right==nullptr) return flag;
    return tem->right->data;
}

template<class T>
void binaryTree<T>::delleft(T x){
    node *tem=find(x,root);
    if (tem==nullptr) return ;
    clear(tem->left);
}

template<class T>
void binaryTree<T>::delright(T x){
    node *tem=find(x,root);
    if (tem=nullptr) return;
    clear(tem->right);
}

template<class T>
string binaryTree<T>::preOrder() const{
    return preOrder(root);
}

template<class T>
string binaryTree<T>::midOrder() const{
    return midOrder(root);
}

template<class T>
string binaryTree<T>::postOrder() const{
    return postOrder(root);
}

template<class T>
void binaryTree<T>::levelOrder() const{
    queue<node*> que;
    node *tem;
    que.enQueue(root);
    while(!que.isEmpty()){
        tem=que.deQueue();
        cout<<tem->data<<" ";
        if (tem->left) que.enQueue(tem->left);
        if (tem->right) que.enQueue(tem->right);
    }
}

template<class T>
void binaryTree<T>::createTree(){
    T x,ldata,rdata;
    node *tem,*l,*r;
    int n;
    cin>>n;        // 读入次数
    int i=0;
    while (i<n){
        cin>>x>>ldata>>rdata;
        l=find(ldata,root);
        r=find(rdata,root);
        if (root==nullptr) {l=new node(ldata);r=new node(rdata);root=new node(x,l,r); }
        else {
        tem=find (x,root);
        if (l==nullptr && ldata!=-1) l=new node (ldata);
        if (r==nullptr && rdata!=-1) r=new node (rdata);
        if (tem!=nullptr){
            tem->left=l;
            tem->right=r;}
        else {
            return;}
        }
        ++i;
        }
    }
// ****************************************************************
// queue.cpp

template<class elemType>
queue<elemType>::queue(){
    front=rear=nullptr;
}

template<class elemType>
queue<elemType>::~queue(){
    node *tem;
    while(front!=nullptr){
        tem=front;
        front=front->next;
        delete tem;
    }
}

template<class elemType>
bool queue<elemType>::isEmpty() const{
    return front==nullptr;
}

template<class elemType>
void queue<elemType>::enQueue(const elemType&x){
    if (rear==nullptr) front=rear=new node(x);
    else rear=rear->next=new node(x);
}

template<class elemType>
elemType queue<elemType>::deQueue(){
    node* tem=front;
    elemType value=front->data;
    front=front->next;
    if (front==nullptr) rear=nullptr;
    delete tem;
    return value;
}
template<class elemType>
elemType queue<elemType>::getHead() const{
    return front->data;
}

template class binaryTree<int> ;