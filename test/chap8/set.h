//
// Created by hsh on 2020/5/5.
//
// 数组实现集合-- ：）

#ifndef CLIONCODE_SET_H
#define CLIONCODE_SET_H

#include <iostream>
using  namespace std;


template <class T>
class set {
    friend set<T> operator* (const set<T> & a, const set<T> & b);
    friend set<T> operator+ (const set<T> & a, const set<T> & b);
    friend set<T> operator- (const set<T> & a, const set<T> & b);

private:
    T *elem;
    int size,volume;
    void doubleSpace();
    bool exist(T x) const;

public:
    set();
    set(const set<T> &a);
    ~set(){delete elem;};

    set &operator= (const set<T> & a);
    int getSize() {return size;}
    bool insert(T x);
    bool earse(T x);
    void display();
};


// 链表实现--  ：）
/*

template <class T>
class set {
    friend set<T> operator* (const set<T> & a, const set<T> & b);
    friend set<T> operator+ (const set<T> & a, const set<T> & b);
    friend set<T> operator- (const set<T> & a, const set<T> & b);
    friend ostream &operator<< (ostream& os,const set<T> &a);
private:
    struct node{
        T data;
        node *next;
        node(T &val,node * n= nullptr):data(val),next(n){}
    };
    node *arr;
    bool exist(const T &x);
    void clear();
    int size;
public:
    set();
    set(const set<T> &a);
    ~set(){delete elem;};

    set &operator= (const set<T> & a);
    int getSize() {return size;}
    bool insert(T &x);
    bool earse(T &x);
    void display();
};

*/

#endif //CLIONCODE_SET_H
