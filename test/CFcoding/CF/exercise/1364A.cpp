//
// Created by hsh on 2020/7/16.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int cases;cin>>cases;
    int n,x;
    while (cases--){
        int res = 0;
        cin>>n>>x;
        vector<int> a(n);
        for (int i=0;i<n;++i){
            cin>>a[i];
        }
        res = 0;int ans = 0;
        for (int i=0;i<n;++i){
            res +=a[i];
            if (res%x) ans = max(ans, i+1);
        }
        res = 0;
        for (int i=n-1;i>=0; --i){
            res += a[i];
            if (res%x) ans = max(ans, n-i);
        }
        if (!ans) ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}

