//
// Created by hsh on 2020/5/3.
//

#ifndef HOMEWORK5_PRIORITYQUEUE_H
#define HOMEWORK5_PRIORITYQUEUE_H

template <class T>
class priorityQueue {
    int maxSize;
    int currentSize;
    T *array;

    void doubleSpace();
    void percolateDown(int hole);
    void buildHeap();

public:
    // priorityQueue(int capacity=32);
    priorityQueue(const T * data,int size);
    ~priorityQueue();
    //T getHead();
    void enQueue(const T & x);
    T deQueue();
    bool isEmpty() const;
    int findMin(int x);
    void decreaseKey(int i, int value);
    void print();
};


#endif //HOMEWORK5_PRIORITYQUEUE_H
