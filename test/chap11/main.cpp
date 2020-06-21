#include <iostream>
using namespace std;

// 算法1： 堆排序
template <class T>
void print(T a[],int size){
    for (int i=0;i<size;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}

template <class T>
void percolateDown(T a[], int hole, int size){
    int child;
    T tmp=a[hole];
    for ( ;hole*2+1 < size; hole=child){
        child=2*hole+1;
        if (child+1 < size && a[child]<a[child+1]) ++child;
        if (a[child] > tmp )  a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}

template <class T>
T heapSort(T a[], int size,int x){
    int i;
    T tmp;
    for (i=size/2;i>=0;i--){
        percolateDown(a,i,size);}

    for (i=size-1;i>=size-x;--i){
        tmp=a[0];a[0]=a[i];a[i]=tmp;
        percolateDown(a,0,i);
    }

    return a[size-x];
}

// 算法2：
// 小顶堆
template <class T>  // 下溯
void percolateDownMin(T a[], int hole, int size){
    int child;
    T tmp=a[hole];
    for ( ;hole*2+1 < size; hole=child){
        child=2*hole+1;
        if (child+1 < size && a[child]>a[child+1]) ++child;
        if (a[child] < tmp )  a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}
// 1 2 3 4 5 6 7 8 9 10 11
// 上溯
template <class T>
void enqueue(T a[], T &x, int size){
    a[size]=x;

    int hole=size;

    for (;hole>0 && x<a[hole/2] ;hole/=2){
        a[hole]=a[hole/2];
    }
    a[hole]=x;
}

template <class T>
T findKth (T a[], int size, int k){
    T *b=new T [k] {0};
    int i=0;
    T tmp;
    for (;i<k;++i){
        enqueue(b,a[i],i);
    }
    for (i=k;i<size;++i){
        if (a[i]>b[0]) {b[0]=a[i]; percolateDownMin(b,0,k);}
    }
    tmp=b[0];
    delete [] b;
    return tmp;
}


int main(){
    int size;
    cin>>size;
    int *array=new int [size];
    for (int i=0;i<size;++i)
        cin>>array[i];
    int search;
    cin>>search;

    cout<<heapSort(array,size,search)<<endl;
    cout<<findKth(array,size,search);
    return 0;
}
