//
// Created by hsh on 2020/4/22.
//

#include "binaryTree.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


string int2string(int n){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}


string binaryTree::preOrder(int root){
    string pre="",mid="",pos="",blank=" ";
    if (root==-1) return "";
    if (root!=-1 && find(elem[root].leftval)==-1 && find(elem[root].rightval)==-1) return int2string(elem[root].data);
    if (root!=-1) mid=int2string(elem[root].data);
    pre=preOrder(find(elem[root].leftval));
    pos=preOrder(find(elem[root].rightval));
    if (pre!="") {mid+=' ';}
    mid+=pre;
    if (pos!="") {mid+=' ';}
    mid+=pos;
    return mid;
}
string binaryTree::midOrder(int root){
    string pre="",mid="",pos="",blank=" ";
    if (root==-1) return "";
    if (root!=-1 && find(elem[root].leftval)==-1 && find(elem[root].rightval)==-1) return int2string(elem[root].data);
    if (root!=-1) mid=int2string(elem[root].data);
    pre=midOrder(find(elem[root].leftval));
    pos=midOrder(find(elem[root].rightval));
    if (pre!="") {pre+=' ';}
    pre+=mid;
    if (pos!="") {pre+=' ';}
    pre+=pos;
    return pre;
}
string binaryTree::postOrder(int root){
    string pre="",mid="",pos="",blank=" ";
    if (root==-1) return "";
    if (root!=-1 && find(elem[root].leftval)==-1 && find(elem[root].rightval)==-1) return int2string(elem[root].data);
    if (root!=-1) mid=int2string(elem[root].data);
    pre=postOrder(find(elem[root].leftval));
    pos=postOrder(find(elem[root].rightval));
    if (pre!="") pre+=' ';
    pre+=pos;
    if (pos!="") pre+=' ';
    pre+=mid;
    return pre;
}

int binaryTree::find(int d){
    if (elem== nullptr) return -1;
    for (int i=1;i<size+1;++i)
    {if (elem[i].data==d) return i;}
    return -1;
}



binaryTree::~binaryTree(){if (elem!=nullptr) delete elem;}
void binaryTree::createTree(int n){
    if (elem!=nullptr)
    {   node *p;p=elem;elem=nullptr;
        delete p;
    }
    size=n;
    elem=new node [size+1];

    int tem=0,l=0,r=0;
    int j=1;
    while (j<n+1) {
        cin >> tem >> l >> r;
        elem[j]=node (tem,l,r,-1);
        ++j;
    }
}
void binaryTree::print(){
    if (elem== nullptr)  {cout<<"blank"<<endl;return;}
    for (int i=1;i<size+1;++i){
        cout<<elem[i].data<<"   "<<elem[i].leftval<<"   "<<elem[i].rightval<<"   "<<elem[i].parentval<<endl;
    }
}



