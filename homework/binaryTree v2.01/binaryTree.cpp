#include "binaryTree.h"
#include <sstream>
#include <string>
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
        if (root!=-1 && elem[root].left==-1 && elem[root].right==-1) return int2string(elem[root].data);
        if (root!=-1) mid=int2string(elem[root].data);
        pre=preOrder(elem[root].left);
        pos=preOrder(elem[root].right);
        if (pre!="") {mid+=' ';}
        mid+=pre;
        if (pos!="") {mid+=' ';}
        mid+=pos;
        return mid;
    }
string binaryTree::midOrder(int root){
    string pre="",mid="",pos="",blank=" ";
    if (root==-1) return "";
    if (root!=-1 && elem[root].left==-1 && elem[root].right==-1) return int2string(elem[root].data);
    if (root!=-1) mid=int2string(elem[root].data);
    pre=midOrder(elem[root].left);
    pos=midOrder(elem[root].right);
    if (pre!="") {pre+=' ';}
    pre+=mid;
    if (pos!="") {pre+=' ';}
    pre+=pos;
    return pre;
    }

string binaryTree::postOrder(int root){
    string pre="",mid="",pos="",blank=" ";
    if (root==-1) return "";
    if (root!=-1 && elem[root].left==-1 && elem[root].right==-1) return int2string(elem[root].data);
    if (root!=-1) mid=int2string(elem[root].data);
    pre=postOrder(elem[root].left);
    pos=postOrder(elem[root].right);
    if (pre!="") pre+=' ';
    pre+=pos;
    if (pos!="") pre+=' ';
    pre+=mid;
    return pre;
}

int binaryTree::find(int d,int root){
    if (root>size) return -1;
    if (root==-1) return -1;
    if (elem[root].data==d) return root;
    find(d,elem[root].left);
    find(d,elem[root].right);
}

binaryTree::~binaryTree(){
    if (elem!=nullptr) delete elem;
}


void binaryTree::createTree(int n){
    if (elem!=nullptr)
    {   node *p;p=elem;elem=nullptr;
        delete p;
    }
    size=n;
    elem=new node [size+1];
    for (int i=1;i<n+1;++i){
        elem[i].data=i;
        elem[i].left=elem[i].right=elem[i].parent=-1;
    }
    int tem=0,l=0,r=0;
    int j=0;
    while (j<n) {
        cin >> tem >> l >> r;
        elem[tem].left=l;
        elem[tem].right=r;
        if (l!=-1) elem[l].parent=tem;
        if (r!=-1) elem[r].parent=tem;
        ++j;
    }
}
string binaryTree::preOrder(){return preOrder(1);}
string binaryTree::midOrder(){return midOrder(1);}
string binaryTree::postOrder(){return postOrder(1);}


