//
// Created by hsh on 2020/5/11.
//

#include "MinMaxHeap.h"
#include <cmath>
template  <class T>
int MinMaxHeap<T>::level (int p){
/*    int compare=1,index=0;
    while (p>=compare) {
        ++index;
        compare*=2;
    }
    return (index-1)%2;
    */
    int v=log(p)/0.693;
    return (v%2);
}


template  <class T>
void MinMaxHeap<T>::VerifyMin(int i, T x){
    for (int gp=i/4;gp>=1&& (x<data[gp]); gp/=4){
        data[i]=data[gp];
        i=gp;
    }
    data[i]=x;
}


template  <class T>
void MinMaxHeap<T>::VerifyMax(int p, T x){
    for (int gp=i/4; gp>0 && (x>data[gp]); gp/=4){
        data[i]=data[gp];
        i=gp;
    }
    data[i]=x;
}


template  <class T>
int MinMaxHeap<T>::findMinSonOrGrandson(int n){
    int min=n*2;
    if (min+1<=length && data[min]>data[min+1]) min++;
    for (int k=4*n; k<=length && k<(n+1)*4;++k ){
        if (data[k]<data[min]) min=k;
    }
    return min;
}


template  <class T>
int MinMaxHeap<T>::findMaxSonOrGrandson(int n){
    int max=2*n;
    if (max+1<=length && data[max]<data[max+1]) max++;
    for (int k=4*n; k<=length && k<4*(n+1) ; ++k){
        if (data[k]>data[max]) max=k;
    }
    return max;
}


template  <class T>
T MinMaxHeap<T>::deleteMax(){
    if (length==1) return data[length--];

    int max;

    if (length==2) max=2;
    else max=( data[2]>data[3] ? 2 :3);
    data[0]=data[max];

    T x=data[length--];

    int i,last=length/2,parent;

    for (i=max;i<=last;){
        max=findMaxSonOrGrandson(i);
        if (x>=data[max]) break;
        data[i]=data[max];

        if (max<=2*i+1) {
            i=max;
            break;
        }

        // 继续过滤
        parent=max/2;
        if (x<data[parent]){
            T tmp=x;
            x=data[parent];
            data[parent]=tmp;
        }
        i=max;
    }

    data[i]=x;
    return data[0];

}


template  <class T>
T MinMaxHeap<T>::deleteMin(){
    data[0]=data[1];
    T x=data[length--];
    int i=1,last=length/2;

    int min;

    while (i<=last) {
        min = findMinSonOrGrandson(i);
        if (x <= data[min]) break;
        else {
            data[i] = data[min];
            if (min<=2*i+1) {
                i=min;
                break;
            }
            else {
                int p=min/2;
                if (x>data[p]){
                    T t=data[p];
                    data[p]=x;
                    x=t;
                }
            }
            i=min;
        }
    }
    data[i]=x;
    return data[o];
}