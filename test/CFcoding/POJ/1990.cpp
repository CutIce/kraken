//
// Created by hsh on 2020/8/4.
//

#include <iostream>
#include <stack>
#include <deque>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> cow;
int n;
cow data[20010];
int tree[20010];
bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.first>b.first;
}
void buildtree(int n){
    tree[1] = data[0].second;
    for (int i=2;i<n;++i){
        tree[i] = tree[i-1] + data[i-1].second;
    }
}

int sum(int i){
    int s = 0;
    while (i>0){
        s += tree[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, pair<int,int> & a){
    while(i<n){
        tree[i] += a.second;
        i += i & -i;
    }
}
int main(){
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>data[i].first>>data[i].second;

    sort(data, data+n,cmp);
//    for (int i=0;i<n;++i)
//        add(i,data[i]);
    buildtree(n);
    ll res = 0;
    for (int i=n-1;i>=1;--i){
        res += data[i].first * tree[i];
    }

//    for (int i=0;i<n;++i)
//        cout<<data[i].first<<"  "<<data[i].second<<"\n";

    return  0;
}