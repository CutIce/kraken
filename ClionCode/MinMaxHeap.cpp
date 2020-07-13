//
// Created by hsh on 2020/5/5.
//

#include "MinMaxHeap.h"
template  <class T>
MinMaxHeap<T>::

template  <class T>
int MinMaxHeap<T>::level(int p);

template  <class T>
void MinMaxHeap<T>::verifyMin(int p,T x);

template  <class T>
void MinMaxHeap<T>::verifyMax(int p,T x);

template  <class T>
int MinMaxHeap<T>::findMinSonOrGrandson(int n);

template  <class T>
int MinMaxHeap<T>::findMaxSonOrGrandson(int n);

template  <class T>
T MinMaxHeap<T>::getMax();

template  <class T>
T MinMaxHeap<T>::getMin();


template  <class T>
T MinMaxHeap<T>::deleteMax();

template  <class T>
T MinMaxHeap<T>::deleteMin();

template  <class T>
bool MinMaxHeap<T>::isEmpty() {return length==0;}


template  <class T>
void MinMaxHeap<T>::insert(T x);