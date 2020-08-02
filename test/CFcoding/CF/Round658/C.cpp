//
// Created by hsh on 2020/7/21.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int num = 0;
        int times = 0;
        string a,b;
        vector<int> res;
        cin>>a>>b;

        for (int i=n-1;i>=0;--i){
            if (num % 2 == 0) {
                if (b[i] == a[(n-1-i)/2]) {++times;res.push_back(1);}
                res.push_back(i+1);
                ++times;
            }
            else {
                if (b[i] != a[(n+i)/2]) {++times;res.push_back(1);}
                res.push_back(i+1);
                ++times;
            }
            num++;
        }
        cout<<times<<" ";
        for (int i=0;i<res.size();++i)
            cout<<res[i]<<" ";
        cout<<endl;
    }
}