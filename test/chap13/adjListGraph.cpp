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


void adjListGraph::dfs( int start,int stop, bool visited[]) const{

    edgeNode* p=verlist[start].head;


    cout<<verlist[start].ver<<" ";
    visited[start]=true;

    if (verlist[start].ver == stop ) return;
    while (p != nullptr) {
        if (! visited[p->end] ) dfs(p->end,stop, visited);
        p=p->next;
    }
}



void adjListGraph::dfs() const{
    bool *visited=new bool [Vers];
    for (int i=0;i<Vers;++i) visited[i]=false;
    // cout<<"the Deepth First Search queue is listed as follow:"<<endl;

    for (int i=0;i<Vers; ++i){
        if (visited[i]) continue;
        dfs(i,Vers,visited);
        cout<<endl;
    }
}

void adjListGraph::dfs(int start,int stop) {
    bool *visited=new bool [Vers];
    for (int i=0;i<Vers;++i) visited[i]=false;

    cout<<verlist[start].ver<<" ";
    visited[start]=true;
    edgeNode *p=verlist[start].head;
    while (p!= nullptr){
        if ( visited[p->end] !=true ) dfs(p->end,stop, visited);
        p=p->next;
        cout<<endl;
    }

}

void adjListGraph::searchForPath(int start, int stop){
    bool *visited=new bool [Vers];
    for (int i=0;i<Vers;++i) visited[i]=false;

    edgeNode *p;
    Stack<int> s;
    s.push(start); visited[start]=true;

    p=verlist[start].head;
    while (!s.isEmpty()){
        if (p== nullptr) {s.pop();p=verlist[s.top()].head;continue;}
        if (visited[p->end]==true ) {while (visited[p->end]==true) p=p->next;continue;}
        s.push(p->end);

        if (p->end == stop) {
            while (!s.isEmpty()){cout<<s.pop();}
            return;
        }
        else p=verlist[p->end].head;
    }
    cout<<"false"<<endl;
    return;
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




void adjListGraph::topsort() const{
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


template <class elemType>
Stack<elemType>::~Stack()
{
    node *tem = Top;
    while (Top!= nullptr)
    {
        tem = Top;
        Top = Top->next;
        delete tem;
    }
}

template <class elemType>
elemType Stack<elemType>::top() const
{
    return Top->data;
}

template <class elemType>
elemType Stack<elemType>::pop()
{
    elemType tem = Top->data;
    node *p = Top;
    Top = Top->next;
    delete p;
    return tem;
}

template <class elemType>
void Stack<elemType>::push(elemType &x)
{
    Top=new node(x, Top);
}


template <class elemType>
bool Stack<elemType>::isEmpty() const
{
    return Top== nullptr;
}

template class Stack<int>;