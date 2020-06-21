//
// Created by hsh on 2020/6/14.
//
// 邻接矩阵表示图
#ifndef TEST_ADJLISTGRAPH_H
#define TEST_ADJLISTGRAPH_H

template <class tver,class tedge>
class grapg{
public:
    virtual void insert(tver x,tver y,tedge w) =0;
    virtual void remove(tver x,tver y) =0;
    virtual bool exist(tver x, tver y) =0;
    int numofVer() const {return Vers;}
    int numofEdge() const {return Edges;}
protected:
    int Vers,Edges;
};

struct EulerNode{
    int NodeNum;
    EulerNode *next;
    EulerNode (int ver) {NodeNum=ver;next= nullptr;}
};

template <class tver,class tedge>
class adjListGraph :public  graph<tver,tedge{
        public:
        adjListGraph(int size,const tver d[]);
        void insert(tver x,tver y, tedge w);
        void remove(tver x,tver y);
        bool exist(tver x,tvery) const;
        ~adjListGraph();

        // 遍历
        void dfs() const;
        void bfs() const;

        void EulerCircuit(tver start);

        private:
        tedge **edge;
        tver *ver;
        tedge noEdge;
        int find(tver v) const{
            for (int i=0;i<Vers;++i)
                if (ver[i]==v) return i;
            return -1;
        }

        void ver
};


#endif //TEST_ADJLISTGRAPH_H
