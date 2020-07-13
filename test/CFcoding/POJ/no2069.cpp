//
// Created by hsh on 2020/7/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int r,n;
    cin>>r>>n;
    while(r!=-1 && n!=-1){
        vector<int> x(n);
        for (int i=0;i<n;++i) cin>>x[i];
        sort(x.begin(),x.end());
        int counts=0;
        int i=0;
        while(i<n){
            int s=x[i++];
            while(i<n && x[i]<=s+r) i++;

            int p = x[i-1];
            while(i<n && x[i]<=p+r) i++;

            counts++;
        }
        cout<<counts<<'\n';
        cin>>r>>n;
    }
    return 0;
}