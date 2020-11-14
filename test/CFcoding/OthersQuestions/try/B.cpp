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

int INF = 1<<20;
struct edge{int to, cost;
    edge(int t,int c):to(t), cost(c){};
};
vector<edge> graph[200001];
typedef pair<int,int> P;
int d[200001];
int hour[200001];
int V,E;
int s,e;

void dijkstra(){
    int tmps,tmpe,tmpc;
    fill(d,d+V,INF);
    fill(hour,hour+V,0);
    priority_queue<P,vector<P>, greater<P> > que;
    cin>>V>>E>>s>>e;
    d[s] = 0; que.push(P(0,s));
    for (int i=0;i<E;++i){
        cin>>tmps>>tmpe>>tmpc;
        graph[tmps].push_back(edge(tmpe,tmpc));
        graph[tmpe].push_back(edge(tmps,tmpc));
    }

    while (!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if (d[v] < p.first ) continue;
        for (int i=0;i<graph[v].size();++i){
            edge e = graph[v][i];
            if (d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

