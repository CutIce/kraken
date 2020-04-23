#include <iostream>
#include "binaryTree.h"
using namespace std;
int main() {
    binaryTree<int> tree;
    tree.createTree();
    int n1,n2;
    cin>>n1>>n2;
    string flag1=int2string(n1);
    string flag2=int2string(n2);

    string pre=tree.preOrder();
    string mid=tree.midOrder();
    string pos=tree.postOrder();
    cout<<pre<<endl<<mid<<endl<<pos<<endl;
    return 0;
}

