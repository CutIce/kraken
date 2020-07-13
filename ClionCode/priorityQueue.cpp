//
// Created by hsh on 2020/5/3.
//

#include "priorityQueue.h"
#include <iostream>
using namespace std;

template  <class T>
void priorityQueue<T>::doubleSpace(){
    T *tem=array;
    maxSize*=2;
    array=new T [maxSize];
    for (int i=0;i<=currentSize;++i)
        array[i]=tem[i];
    delete [] tem;
}


template  <class T>
void priorityQueue<T>::percolateDown(int hole){
    int child;
    T tem=array[hole];

    for (; hole*2<=currentSize;hole=child){
        child=hole*2;
        if (child!=currentSize && array[child+1]<array[child])
            child++;
        if (array[child]<tem)
            array[hole]=array[child];
        else break;
    }
    array[hole]=tem;
}


/*
template  <class T>
priorityQueue<T>::priorityQueue(int capacity=32){
    maxSize=capacity;
    currentSize=0;
    array=new T [maxSize];
}
*/

template  <class T>
void priorityQueue<T>::buildHeap(){
    for (int i=currentSize/2;i>=1;i--){
        percolateDown(i);
    }
}


template  <class T>
priorityQueue<T>::priorityQueue(const T * data,int size){
    maxSize=2*size;
    currentSize=size;
    array=new T [maxSize];
    for (int i=0;i<currentSize;++i)
        {array[i+1]=data[i];}

    buildHeap();
}

template  <class T>
priorityQueue<T>::~priorityQueue(){
    delete [] array;
}
/*
template  <class T>
T priorityQueue<T>::getHead(){
    if (currentSize>0)
    return array[1];
    else return -1;
}
 */

template  <class T>
void priorityQueue<T>::enQueue(const T  & x){
    ++currentSize;
    if (currentSize==maxSize) doubleSpace();

    array[currentSize]=x;
    int hole=currentSize;    // the hole will be used later so we should put it out of the for-loop
    for (  ;hole>1 && array[hole/2]>x  ;  hole/=2){
        array[hole]=array[hole/2];
    }
    array[hole]=x;
}

template  <class T>
T priorityQueue<T>::deQueue(){
    T tem=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
    return tem;
}


template  <class T>
bool priorityQueue<T>::isEmpty() const{
    return currentSize==0;
}

template  <class T>
int priorityQueue<T>::findMin(int x){                         // use index record the location--- number
    int index=-1;
    T tem;
    for (int i=1;i<=currentSize;++i){
        if (array[i]>=x){
            if (index==-1 || array[i]< tem){ index=i;tem=array[i];}
        }
    }
    if (index!=-1) return index;
    cout<<"no exist"<<endl;
    while (!isEmpty()){
        cout<<deQueue()<<" ";
    }
    return -1;
}


template  <class T>
void priorityQueue<T>::decreaseKey(int i, int value){
    array[i]-=value;
    if (array[i]<0) array[i]=0;
    T x;
    int hole=i;    // the hole will be used later so we should put it out of the for-loop
    for ( x=array[i] ;hole>1 && array[hole/2]>x  ;  hole/=2){
        array[hole]=array[hole/2];
    }
    array[hole]=x;
}


template  <class T>
void priorityQueue<T>:: print(){
    for (int i=1;i<=currentSize;++i)
        cout<<array[i]<<" ";
}


template class  priorityQueue<int> ;