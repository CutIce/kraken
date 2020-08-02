//
// Created by hsh on 2020/7/24.
//

#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;
int par[2020];
int ran[2020];
int n;
int kind;
void init(int n, int k){
    for (int i=0; i<k;++i){
        for (int j=i;j<n;j+=k-1)
            par[j] = i;
    }
}

int find(int x){
    if (par[x] == x) return x;
    else return par[x] =find(par[x]);
}

void unit(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (ran[x] < ran[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (ran[x] == ran[y]) ran[x]++;
    }
    --kind;
}

int main(){

    int m,k;
    cin>>n>>m>>k;
    kind = k;
    init(n,k);
    int i=0;
    for (i=0; i<k/2+1 && i<n;++i){
        unit(i,k-1-i);
    }
    for (int j=n-1; j>=0  && j>= n-k+1 ;--j){
        unit(j,2*n- k -1-j);
    }
    cout<<kind<<endl;
    long res = 1;
    for (int i=0;i<kind;++i)
        res *=m;
    cout<<res%(100000007);
}

//int size = n;
//for (int j=0;j<=2*k && j+k<n; ++j)
//{
//int peer = k-1-j;
//unit(j,peer);
//}
////
//int ans =0;
//if (k == n) {
//if (k%2 ==0) ans =k/2;
//else  ans = k/2 + 1;
//}
//else if (k < n)
//ans = 1;
//long res = 1;
//for (int i=0;i<ans;++i){
//res *=m;
//}