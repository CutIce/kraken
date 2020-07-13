//
// Created by hsh on 2020/5/5.
//

#include "set.h"


template <class T>
friend set<T> operator* (const set<T> & a, const set<T> & b);

template <class T>
friend set<T> operator+ (const set<T> & a, const set<T> & b);


template <class T>
friend set<T> operator- (const set<T> & a, const set<T> & b);

template <class T>
void doubleSpace(){
    T *tem=elem;
    elem=new T [2*volume];
    for (int i=0;i<size;++i)
}

template <class T>
bool exist(T x) const;

template <class T>
set<T>::set(){
    volume=20;
    size=0;
    elem=new T [volume];
}

template <class T>
set<T>::set(const set<T> &a){
    volume=a.volume;
    size=a.size;
    elem=new T [volume];
    for (int i=0;i<size;++i)
        elem[i]=a.elem[i];
}


template <class T>
set &operator= (const set<T> & a);

template <class T>
bool insert(T x);


template <class T>
bool earse(T x);

template <class T>
void display();