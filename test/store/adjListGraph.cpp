//
// Created by hsh on 2020/6/14.
//

#include "adjListGraph.h"
#include <iostream>
#include <string>
using namespace std;

// construct and destruct function

adjListGraph<int,int>::adjListGraph(int Vsize,int d[]){
    Vers=Vsize;
    Edges=0;
    verlist=new verNode [Vers];
    for (int i=0;i<Vers;++i)  verlist[i].ver=d[i];
}



adjListGraph<int,int>::~adjListGraph(){
    int i;
    edgeNode* p;

    for (i=0;i<Vers;++i){
        while ((p=verlist[i].head)!= nullptr){
            verlist[i].head=p->next;z
            delete p;
        }
    }
    delete [] verlist;
}

// the functions which can change something of the data
// including insert  remove  exist function



void adjListGraph<int,int>::insert(int x,int y, int w){
    int u=find(x);
    int v=find(y);
    if (u<0 || v<0) return;
    verlist[u].head=new edgeNode (v,w,verlist[u].head);
    ++Edges;
}




void adjListGraph<int,int>::remove(int x,int y){
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

    while (p->next!=nullptr && p->next->end !=end) p=p->next;

    if (p->next!= nullptr) {
        q=p->next;
        p->next=q->next;
        delete q;
        --Edges;
    }
}


// the functions which can fully traverse the data structure  and we can also get some funny things within those processes


string adjListGraph<int,int>::dfs( int start, bool visited[]) const{
    string s="";
    edgeNode* p=verlist[start].head;

    s+=string(verlist[start].ver);
    visited[start]=ture;

    while (p != nullptr) {
        if (! visited[p->end]  )dfs(p->end,visited);
        p=p->next;
    }
}



string adjListGraph<int,int>::dfs() const{
    string res="";
    bool *visited=new bool [Vers];
    for (int i=0;i<Vers;++i) visited[i]=false;
    // cout<<"the Deepth First Search queue is listed as follow:"<<endl;

    for (int i=0;i<Vers; ++i){
        if (visited[i]) continue;
        res+=dfs(i,visited);
        res+="  |  ";
    }
}




void adjListGraph<int,int>::bfs() const{
    bool*visited=new bool [Vers];
    int currentnode;
    queue<int> q;

    edgeNode* p;

    for (int i=0;i<Vers;++i) visited[i]=false;

    cout<<"the BFS of this graph is listed as follow:"\\<<'\t';

    for (int i=0;i<Vers;++i){
        if (visited[i]) continue;
        q.enqueue(i);
        while (!q.isempty()){
            currentnode=q.dequeue();
            if ( visited[currentnode] ) continue;
            cout<<verlist[currentnode].ver<<'\t';
            visited[currentnode]=true;
            p=verlist[currentnode].head;
            while(p!= nullptr){
                if (! visited[p->end] ) q.enqueue(p->end);
                p=p->next;
            }
        }
        cout<<endl;
    }
}




void adjListGraph<int,int>::topsort() const{
    queue<int> q;
    edgeNode* p;
    int current;
    int *inDegree = new int[Vers];

    for (int i=0;i<Vers;++i) inDegree[i]=0;
    for (int i=0;i<Vers;++i){        // 计算入度
        for (p=verlist[i].head;p!= nullptr;p=p->next){
            ++inDegree[p->end];
        }
    }

    for (int i=0;i<Vers;++i) if ( inDegree[i]== 0 ) q.enqueue(i);

    cout<<"the Top Sort of this graph:"<<endl;
    while(!q.isempty()){
        current=q.dequeue();
        cout<<verlist[current].ver<<'\t';

        for (p=verlist[current].head;p!= nullptr;p=p->next){
            if ( --inDegree[p->end]==0) q.enqueue(p->end);
        }
    }
    cout<<endl;
}

