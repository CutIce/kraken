#include "priorityQueue.h"
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int * data=new int [n];
    for (int i=0;i<n;++i){
        cin>>data[i];}
    priorityQueue<int> pqueue(data,n);

    int x;          cin>>x;
    int value;      cin>>value;

    int i;          i=pqueue.findMin(x);
    if (i!=-1){
    pqueue.print();  cout<<endl;
    pqueue.decreaseKey(i,value);
    pqueue.print();  cout<<endl;

    while (! pqueue.isEmpty()){
        cout<<pqueue.deQueue()<<" ";
    }}

    return 0;
}