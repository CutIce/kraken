//
// Created by hsh on 2020/4/22.
//

#include <iostream>
#include <sstream>
#include <string>
#include "binaryTree.h"
using namespace std;
string intTostring(int n){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}
bool inarray(int a[],int b[],int n,int data);
int main(){
    binaryTree tree;
    int n;
    cin>>n;
    tree.createTree(n);
    int n1,n2;
    cin>> n1>>n2;
    cout<<tree.midOrder()<<endl;

    string pre=tree.preOrder(),pos=tree.postOrder();

    int res=-1;int tem=-1;
    int* num1=new int [n]{0};  int i=0;
    int* num2=new int [n]{0};  int j=0;
    stringstream ss1,ss2;
    ss1<<pre;    while (i<n) {ss1>>tem;num1[i]=tem;++i;}
    ss2<<pos;    while (j<n) {ss2>>tem;num2[j]=tem;++j;}
//    cout<<"pre"<<pre<<"----------------"<<"pos"<<"   "<<pos<<endl;
    if (inarray(num1,num2,n+1,n1) && inarray(num1,num2,n+1,n2)){
    for (i=0;i<n;++i){if (num1[i]==n1||num1[i]==n2) break; }
    for (j=n-1;j>=0;--j){if (num2[j]==n1||num2[j]==n2) break; }

    for (int p=i;p>=0;--p){
        for (int q=j;q<n;++q) {if (num1[p]==num2[q])  {res=num1[p];break;} }
        if (res!=-1) break;}

    delete num1;delete num2;
    if (res!=-1) cout<<res<<endl;
    else cout<<"error"<<endl;}
    else cout<<"error"<<endl;
    return 0;

}

bool inarray(int a[],int b[],int n,int data){
    bool flag1=false,flag2=false;
    for (int i=1;i<n;++i){
        if (a[i]==data) {flag1=true;break;}
    }
    for (int i=1;i<n;++i)
        if (b[i]==data) {flag2=true;break;}

    return flag1&&flag2;
}