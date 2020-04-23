#include <iostream>
#include <sstream>
#include "binaryTree.h"
using namespace std;
string intTostring(int n);
int main(){
    binaryTree tree;
    int n=0;
    cin>>n;
    tree.createTree(n);
    int n1,n2;
    cin>>n1>>n2;
    string mid=tree.midOrder();
    string pre=tree.preOrder();
    string pos=tree.postOrder();
    cout<<mid<<endl;
    string s1=intTostring(n1);
    string s2=intTostring(n2);

    int res=-1;int tem=-1;
    int* num1=new int [n]{0};  int i=0;
    int* num2=new int [n]{0};  int j=0;
    stringstream ss1,ss2;
    ss1<<pre;    while (i<n) {ss1>>tem;num1[i]=tem;++i;}
    ss2<<pos;    while (j<n) {ss2>>tem;num2[j]=tem;++j;}
//    cout<<"pre"<<pre<<"----------------"<<"pos"<<"   "<<pos<<endl;


    for (i=0;i<n;++i){if (num1[i]==n1||num1[i]==n2) break; }
    for (j=n-1;j>=0;--j){if (num2[j]==n1||num2[j]==n2) break; }

    for (int p=i;p>=0;--p){
        for (int q=j;q<n;++q) {if (num1[p]==num2[q])  {res=num1[p];break;} }
        if (res!=-1) break;}

    delete num1;delete num2;
    if (res!=-1) cout<<res<<endl;
    else cout<<"error"<<endl;
    return 0;
}
string intTostring(int n){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}


