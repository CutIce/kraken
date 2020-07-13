//
// Created by hsh on 2020/7/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    int *data = new int [n];
    int *dp = new int [n];
    int res = 0;

    for (int i=0;i<n;++i){
        dp[i] = 1;
        for (int j=0;j<i;++j){
            if (data[j] < data[i])
                dp[i]=max(dp[j]+1,dp[i]);
        }
        res = max(res,dp[i]);
    }
    cout<<res<<endl;
    return 0;
}