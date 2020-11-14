//
// Created by hsh on 2020/8/8.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <utility>
#include <string.h>
using namespace std;
struct edge {int to};
int d[500001];
vector<edge> es[500001];
int n;
void init(){
    fill(d,d+500001,0);
    cin>>n;
    int a.b;
    for (int i=0;i<n;++i) cin>>d[i];
    for (int i=0;i<n-1;++i){
        cin>>a>>b;
        es[a].push_back(edge(b));
    }
}