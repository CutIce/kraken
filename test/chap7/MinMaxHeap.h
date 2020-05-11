//
// Created by hsh on 2020/5/11.
//

#ifndef TEST_MINMAXHEAP_H
#define TEST_MINMAXHEAP_H

template  <class T>
class MinMaxHeap {

private:
    T * data;
    int length;
    int size;

    int level (int p);
    void VerifyMin(int i, T x);
    void VerifyMax(int i, T x);
    int findMinSonOrGrandson(int n);
    int findMaxSonOrGrandson(int n);

public:
    MinMaxHeap(int n=100):length(0),size(n) {data=new T [size];};
    ~MinMaxHeap() {delete [] data;};

    void insert(T x);
    T getMax() {
        if (length==1) {return data[1];}
        if (length==2) return data[2];
        if (length>=3) return (data[2]>data[3] ? data[2]:data[3]);
    };
    T getMin() {    return data[1];    }
    T deleteMax();
    T deleteMin();
    bool isEmpty() {return length==0;}
};


#endif //TEST_MINMAXHEAP_H
