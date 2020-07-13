//
// Created by hsh on 2020/6/14.
//

#include "adjListGraph.h"
#include <iostream>
#include <sstream>
using namespace std;


int main(){

    int n;
    cin>>n;
    cin.get();
    int *d=new int[n];
    for (int j=0;j<n;++j) d[j]=j;
    adjListGraph gra(n,d);
    queue<int> q;
    int form=-1,latter=-1; char comma;

    do{
        cin>>form>>comma>>latter;
        gra.insert(form,latter,1);
        comma=cin.get();
    }while (comma == ' ');

    cin>>form>>latter;

    // gra.print();
    if (! gra.dfs(form,latter))
        cout<<"false";
    //gra.searchForPath(form,latter);


}

