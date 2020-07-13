#ifndef TEST_ADJLISTGRAPH_H
#define TEST_ADJLISTGRAPH_H

#include <string>
using namespace std;

template <class elemType>
class queue{
public:
    queue(){front=rear=nullptr;};
    ~queue() {
        node *p=front;
        while (front){
            p=front;
            front=front->next;
            delete p;}}
    void enqueue(elemType &x){
        if ( rear == nullptr ) front = rear = new node(x);
        else rear = rear->next = new node(x);
    }
    elemType dequeue(){
        elemType tmp=front->data;
        node *p=front;
        front=front->next;
        if (front == nullptr ) rear= nullptr;
        delete p;
        return tmp;
    };
    elemType gethead() const { return front->data;};
    bool isempty(){return front== nullptr;}
private:
    struct node{
        elemType data;
        node *next;
        node(elemType & x,node *p= nullptr){data=x,next=p;}
        node():next(nullptr) {};
        ~node();
    };
    node *front,*rear;
};


// 邻接表定义
class adjListGraph {
public:
    adjListGraph(int Vsize,int d[]);
    void insert(int x,int y, int w);
    void remove(int x,int y);
    bool exist(int x,int y) const{
        int u=find(x),v=find(y);
        if ( u<0 || v<0 ) return false;
        edgeNode*p=verlist[u].head;
        while (p && p->end != v) p=p->next;
        if (p== nullptr) return false;
        else return true;
    };
    ~adjListGraph();

    // 遍历
    string dfs() const;
    void bfs() const;
    void topsort() const;

private:
    int Vers,Edges;

    struct edgeNode
    {
        int end;
        int weight;
        edgeNode *next;
        edgeNode (int e, int w,edgeNode *n=nullptr){end=e,weight=w,next=n;}
    };

    struct verNode{
        int ver;
        edgeNode* head;   // the coresponding head of list  // use a list to restore the edges of a certain verNode

        verNode(edgeNode *h= nullptr)  {head=h;}
    };

    verNode *verlist;
    int find(int v) const{
        for (int i=0;i<Vers;++i)
            if ( verlist[i].ver == v ) return i ;
        return -1;
    }

    string dfs(int start, bool visited[]) const;

#endif //TEST_ADJLISTGRAPH_H
