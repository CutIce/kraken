#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int cases;cin>>cases;
    int n;
    int x;
    while(cases--){
        int counts=0;
        cin>>n>>x;
        vector<int> data(n);
        for (int i=0;i<n;++i)   cin>>data[i];
        sort(data.begin(), data.end());
        int start = 0,end = n-1,last=n;   // end - start + 1
        while(end>=0){
            if (data[end]*(last-end) >=x)
            {counts++;last = end;}
            end--;
        }
        cout<<counts<<endl;
    }
    return 0;
}

/*
       sort(data.begin(), data.end());
        if ( data[0]*data[n-1] < x){
            cout<<0<<endl;continue;}
        counts=1;start=1,end=n-2;
        while(  start < end){
            if (data[start] * data[end] >= x){
            counts++;
            start++;
            end--;}
            else ++start;
        }
        cout<<counts<<endl;
    }
1
8 40
88 9 12 67 78 1 2 3   10
 * */

/* 2 3 4 5 6 7 89
        int res;
        while( start < end){
            if (x%data[start] ==0){
                res = n/data[start];}
            else {
                res = x/data[start]+1;}
            bool skip=false;
            int i=start+1;
            while(i<start+res){
                if ( data[i] * (res+start-i) >= x )
                {skip = true; break;}
                else ++i;
            }
            if (skip) ++start;
            else {start+=res-1;counts++;}
        }
        if (res>1) --counts;
        cout<<counts<<endl;
 * */