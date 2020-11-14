//
// Created by hsh on 2020/8/6.
//
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;
const int max_n = 10000;
const int INF = 1<<12;
int d[max_n];
bool used[max_n];
int V;
struct edge{int from,to,cost};
typedef pair<int,int> P;
vector<edge> G[max_n];

void Dijkstra(int s){
    fill(d,d+V,INF);d[s] = 0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    while (!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i=0;i<G[v].size();++i){
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int dist[max_n][max_n];
void floyd_warshell(){
    for (int k=0;k<V;++k){
        for (int i=0;i<V;++i){
            for (int j=0;j<V;++j){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

// 路径还原
int prev[max_n];

void digistra(int s){
    fill(d,d+V,INF);
    fill(used,used+V,false);
    fill(prev,prev+V,-1);
    d[s] = 0;

    while (true){
        int v = -1;
        for (int u=0;u<V;++u){
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if (v == -1) braek;
        used[v] = true;

        for (int u =0;u<V;++u){
            if (d[u] > d[v] + cost[u][v] ){
                d[u] = d[v] + cost[u][v];
                pres[u] = v;
            }
        }
    }
}

vector<int> get_path(int t){
    vector<int> path;
    for (; t!=-1;t=prev[t]) path.push_back(t);
    reversr(path.begin(),path.end());
    return path;
}