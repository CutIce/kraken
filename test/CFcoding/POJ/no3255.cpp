//
// Created by hsh on 2020/7/12.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge{
    int from,to,cost;
    edge(int f=0,int t=0,int c=0): from(f),to(t),cost(c) {};
};
vector<edge> g[5001];
typedef  pair<int, int> P;
int dist[5001];
int dist2[5001];
const int INF = 10000;

int n,r;

void solve(){
    priority_queue<P, vector<P>, greater<P>> que;

    fill(dist, dist+n, INF);
    fill(dist2, dist2+n,INF);
    dist[0]=0;
    que.push(P(0,0));

    while(!que.empty()){
        P p = que.top();que.pop();
        int v= p.second, d= p.first;
        if (dist2[v] < d) continue;
        for (int i=0;i<g[v].size();++i){
            edge &e = g[v][i];
            int d2 = d + e.cost;
            if (dist[e.to] > e.to){
                swap(dist[e.to],d2);
                que.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2){
                dist2[e.to] = d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    cout<<dist2[n-1]<<endl;
}

int main(){
    cin>>n>>r;
    int f,t,c;
    while(r--){
        cin>>f>>t>>c;
        edge e(f,t,c);
        g[f].push_back(e);
    }
    solve();
    return 0 ;
}