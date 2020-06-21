//
// Created by hsh on 2020/5/20.
//

#ifndef TEST_SORT_H
#define TEST_SORT_H

#include <iostream>
using namespace std;

template <class KEY,class OTHER>
struct set{
    KEY key;
    OTHER other;
};

//简单插入排序
template <class KEY,class OTHER>
void print(set<KEY,OTHER> a[], int size){
    for (int i=0;i<size;++i)
        cout<<a[i].key<<" ";

    cout<<endl;
}


template <class KEY,class OTHER>
void simpleInsertSort(set<KEY,OTHER> a[], int size){
    int k;
    set<KEY,OTHER> tmp;

    for (int j=1;j<size;++j){
        tmp=a[j];
        for (k=j-1;k>=0 && tmp.key<a[k].key;--k){
            a[k+1]=a[k];
        }
        a[k+1]=tmp;

     print(a,size);
    }
}


// 希尔排序
template <class KEY,class OTHER>
void shellSort(set<KEY,OTHER> a[], int size){
    int step,i,j;
    set<KEY,OTHER> tmp;

//    for (step=size/2; step>0; step/=2){
//        for (i=step;i<size;++i){
//            tmp=a[i];
//            for (j=i-step;j>=0 && a[j].key>tmp.key ; j-=step)
//                a[j+step]=a[j];
//
//            a[j+step]=tmp;
//        }
//    }

    for (step=5; step>=1; step-=2){
        for (i=step;i<size;++i){
            tmp=a[i];
            for (j=i-step;j>=0 && a[j].key>tmp.key ; j-=step)
                a[j+step]=a[j];

            a[j+step]=tmp;
        }
        print(a,size);
    }
}


// 简单选择排序
template <class KEY,class OTHER>
void simpleSelectSort(set<KEY,OTHER> a[], int size){
    int i,j,min;

    set<KEY,OTHER> tmp;

    for (i=0;i<size-1;++i){
        min=i;
        for (j=i+1; j<size;++j){
            if (a[j].key < a[min].key )  min=j;
        }
        tmp=a[i];            // exchange a[i] and a[min]
        a[i]=a[min];
        a[min]=tmp;

        //print(a,size);
    }
}


// 向下过滤
template <class KEY,class OTHER>
void percolateDown(set<KEY,OTHER> a[], int hole, int size){
    int child;
    set<KEY,OTHER> tmp=a[hole];

    for ( ;hole*2+1 <size; hole=child){
        child=2*hole+1;
        if (child+1 < size && a[child].key<a[child+1].key) ++child;
        if (a[child].key > tmp.key )  a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}


// 堆排序
template <class KEY,class OTHER>
void heapSort(set<KEY,OTHER> a[], int size){
    int i;
    set<KEY,OTHER> tmp;

    for (i=size/2;i>=0;i--){
        percolateDown(a,i,size);
    }

    print(a,9);
    cout<<endl;


    for (i=size-1;i>0;--i){
        tmp=a[0];a[0]=a[i];a[i]=tmp;
        percolateDown(a,0,i);
        print(a,9);
    }
}


// 冒泡排序
template <class KEY,class OTHER>
void bubbleSort(set<KEY,OTHER> a[], int size){
    int i,j;
    set<KEY,OTHER> tmp;
    bool flag=true;

    for (i=0;i<size && flag;++i){
        flag=false;
        for (j=0;j<size-i ;++j){
            if (a[j].key>a[j+1].key){
                tmp.key=a[j].key;
                a[j].key=a[j+1].key;
                a[j+1].key=tmp.key;
                flag=true;
            }
        }
        print(a,9);
    }
}

// 快速排序
template <class KEY,class OTHER>
int divide(set<KEY,OTHER> a[], int low, int high){
    set<KEY,OTHER> k=a[low];
    do {
        while (low<high && a[high].key >=k.key) --high;
        if (low < high)  {a[low]=a[high]; ++low;}
        while (low<high && a[low].key<=k.key)  ++low;
        if (low<high)   {a[high]=a[low]; --high;};
    }while(low!=high);

    a[low]=k;
    print(a,9);
    return low;
}



template <class KEY,class OTHER>
void quickSort(set<KEY,OTHER> a[], int low, int high){
    int mid;
    if (low>=high) return;

    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
    //print(a,9);
    //print(a,9);

}


template <class KEY,class OTHER>
void quickSort(set<KEY,OTHER> a[], int size){
    quickSort(a,0,size-1);
}


//归并排序
template <class KEY,class OTHER>
void merge(set<KEY,OTHER> a[],int left, int mid, int right){
    set<KEY,OTHER> *tmp=new set<KEY,OTHER> [right-left+1];

    int i=left,j=mid,k=0;

    while (i<mid && j<=right){
        if (a[i].key<a[j].key) {tmp[k]=a[i]; ++i;}
        else {tmp[k]=a[j]; ++j;};
        ++k;
    }

    while (i<mid)  {tmp[k]=a[i];++i;++k;}
    while (j<right+1) {tmp[k]=a[j];++j;++k;}

    for (i=left,k=0;i<right+1; ++i,++k) a[i]=tmp[k];
    delete [] tmp;
    print(a,9);
}


template <class KEY,class OTHER>
void mergeSort(set<KEY,OTHER> a[], int left, int right){
    int mid=(left+right)/2;
    if (left==right) return ;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid+1,right);

}


template <class KEY,class OTHER>
void mergeSort(set<KEY,OTHER> a[], int size){
    mergeSort(a,0,size-1);

}


// 口袋排序
template <class OTHER>
struct node{
    set<int,OTHER> data;
    node * next;

    node(){next= nullptr;}
    node(set<int,OTHER> d,node *p= nullptr){data=d,next=p;}
};

template <class OTHER>
void bucketSort(node<OTHER> *&p){
    if (p== nullptr) return;

    node<OTHER> *bucket[10],*last[10],*tail;
    int i,j,k,base=1,max=0,len=0;

    for (tail=p;tail!= nullptr; tail=tail->next)
        if (tail->data.key>max) max=tail->data.key;

    if (max==0) len=0;
    else while (max>0) {++len; max/=10;}

    for (i=1;i<len;++i){
       for (j=0;j<=9;++j) bucket[j]=last[j]= nullptr;

       while (p!= nullptr){
           k=p->data.key/base %10;
           if (bucket[k]== nullptr) bucket[k]=last[k]=p;
           else last[k]=last[k]->next=p;
           p=p->next;
       }
       p= nullptr;

       for (j=0;j<=9;++j){
           if (bucket[j]== nullptr) continue;
           if (p== nullptr)p=bucket[j];
           else tail->next=bucket[j];
           tail=last[j];
       }

       tail->next= nullptr;
       base*=10;
    }
}

#endif //TEST_SORT_H
