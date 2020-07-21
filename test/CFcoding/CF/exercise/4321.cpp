#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct edge {
    int to;
    int w;
    edge (int t, int wi) :to(t),w(wi){}
};
vector<edge>  g[10001];

int main(){
    int n,m,k;cin>>n>>m>>k;
    int from,to, weight;
    for (int i;i<m;++i){
        cin>>from>>to>>weight;
        edge e(to,weight);
        g[from].push_back(e);
    }
/*    for (int i=0;i<n;++i){
        cout<<i<<" :"<<endl;
        for (int j=0; j<g[i].size();++j)
            cout<<g[i][j].to<<" "<<g[i][j].w<<" "<<endl;
    }*/


}