#include "adjListGraph.h"
#include <iostream>
#include <string>
using namespace std;

// construct and destruct function

adjListGraph::adjListGraph(int Vsize,int d[]){
    Vers=Vsize;
    Edges=0;
    verlist=new verNode [Vers];
    for (int i=0;i<Vers;++i)  verlist[i].ver=d[i];
}



adjListGraph::~adjListGraph(){
    int i;
    edgeNode* p;

    for (i=0;i<Vers;++i){
        while ((p=verlist[i].head)!= nullptr){
            verlist[i].head=p->next;
            delete p;
        }
    }
    delete [] verlist;
}

// the functions which can change something of the data
// including insert  remove  exist function



void adjListGraph::insert(int x,int y, int w){
    int u=find(x);
    int v=find(y);
    if (u<0 || v<0) return;
    verlist[u].head=new edgeNode (v,w,verlist[u].head);
    ++Edges;
}




/*
void adjListGraph::remove(int x,int y){
    int u=find(x),v=find(y);
    if (u<0 || v<0) return ;
    edgeNode* p=verlist[u].head;
    edgeNode* q;

    if (!p) return ;

    if (p->end == v) {
        verlist[u].head=p->next;
        delete p;
        --Edges;
        return;
    }

    while (p->next!=nullptr && p->next->end != end ) p=p->next;

    if (p->next!= nullptr) {
        q=p->next;
        p->next=q->next;
        delete q;
        --Edges;
    }
    }
*/



// the functions which can fully traverse the data structure  and we can also get some funny things within those processes


void adjListGraph::dfs( int start, bool visited[]) const{

    edgeNode* p=verlist[start].head;


    cout<<verlist[start].ver<<" ";
    visited[start]=true;

    while (p != nullptr) {
        if (! visited[p->end] ) dfs(p->end, visited);
        p=p->next;
    }
}


bool adjListGraph::dfs(int start,int stop) {
    bool *visited=new bool [Vers];
    for (int i=0;i<Vers;++i) visited[i]=false;
    queue<int> q;

    q.enqueue(verlist[start].ver);
    //cout<<verlist[start].ver<<" ";
    visited[start]=true;
    edgeNode *p=verlist[start].head;
    while (p!= nullptr){
        if ( visited[p->end] !=true ) if (dfs(p->end,stop, q,visited)) return true;
        p=p->next;
    }
    return false;
}

bool adjListGraph::dfs(int start,int stop, queue<int> q,bool visited[]) {
    q.enqueue(verlist[start].ver);
    visited[start]=true;
    if (start==stop) {while(!q.isempty()) cout<<q.dequeue()<<" "; return true;}
    edgeNode *p=verlist[start].head;
    while (p!= nullptr){
        if ( visited[p->end] !=true ) if (dfs(p->end,stop, q, visited)) return true;
        p=p->next;
    }
    return false;
}



void adjListGraph::bfs() const{
    bool*visited=new bool [Vers];
    int currentnode;
    queue<int> q;

    edgeNode* p;

    for (int i=0;i<Vers;++i) visited[i]=false;

    cout<<"the BFS of this graph is listed as follow:"<<endl;

    for (int i=0;i<Vers;++i){
        if (visited[i] == true ) continue;
        q.enqueue(i);
        while (!q.isempty()){
            currentnode=q.dequeue();
            if ( visited[currentnode] == true ) continue;
            cout<<verlist[currentnode].ver<<'\t';
            visited[currentnode]=true;
            p=verlist[currentnode].head;
            while(p!= nullptr){
                if (! visited[p->end] == false ) q.enqueue(p->end);
                p=p->next;
            }
        }
        cout<<endl;
    }
}

