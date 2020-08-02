//
// Created by hsh on 2020/7/30.
//

#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <tuple>
#include <algorithm>
#include <deque>
#include <utility>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    int tmpt,tmpc;
    vector<pair<int,int>> police;
    for (int i=0;i<n;++i) cin>>a[i];
    for (int i=0;i < m; ++i ){
        cin>>tmpt>>tmpc;
        if ((double)tmpc/tmpt < k) {pair<int,int> tem(tmpt,tmpc);
            police.push_back(tem);
        }

    }

}