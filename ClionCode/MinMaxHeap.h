//
// Created by hsh on 2020/5/5.
//

#ifndef CLIONCODE_MINMAXHEAP_H
#define CLIONCODE_MINMAXHEAP_H

template<class T>
class MinMaxHeap {
private:
    T * data;
    int length;
    int size;
    int level(int p);
    void verifyMin(int p,T x);
    void verifyMax(int p,T x);
    int findMinSonOrGrandson(int n);
    int findMaxSonOrGrandson(int n);

public:
    MinMaxHeap(int n=100): size(n+1),length(n){
        data=new T [size];
    }
    ~MinMaxHeap() {delete data;}

    void insert(T x);
    T getMax();
    T getMin();
    T deleteMax();
    T deleteMin();
    bool isEmpty() {return length==0;}
};


#endif //CLIONCODE_MINMAXHEAP_H
