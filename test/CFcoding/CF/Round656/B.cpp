//
// Created by hsh on 2020/7/17.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int tmp,n;cin>>n;
        vector<int> exist(n+1);
        vector<int> a;
        for (int i=1;i<n+1;++i) exist[i] = 0;

        for (int i=0;i<2*n;++i){
            cin>>tmp;
            if (exist[tmp] == 0) {exist[tmp] = 1;a.push_back(tmp);}
        }
        for (int i=0;i<n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
}