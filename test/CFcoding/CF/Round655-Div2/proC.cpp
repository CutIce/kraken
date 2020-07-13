//
// Created by hsh on 2020/7/11.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


int main(){
    int cases,n;
    cin>>cases;
    while(cases--){
        cin>>n;
        vector<int> a(n+1);
        vector<bool> is(n+1);
        for (int i =1; i<n+1;++i){
            cin>>a[i];
            if ( a[i] == i) is[i] = true;
            else is[i] = false;
        }
        int end=n;
        while(is[end]){
            --end;
        }
        int start =1;
        while(is[start]){
            ++start;
        }
        if ( end == 0 ) {cout<<0<<endl;continue;}
        else {
            bool flag=false;
            for (int i=start;i<end;++i)
                if (is[i] == true) flag = true;
                if (flag) cout<<2<<endl;
                else cout<<1<<endl;
        }
    }
    return 0;
}