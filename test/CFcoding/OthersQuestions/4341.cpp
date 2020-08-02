//
// Created by hsh on 2020/7/31.
//

#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <string.h>

using namespace std;


int main(){
    long  a[100100];
    long  sum[100010];
    int n;  cin>>n;
    for(int i=0;  i<n;  ++i) cin>>a[i];
    long ans = 0;
    sum[n-1] = a[n-1];
    for (int i=n-2;  i>=0;  --i){
        sum[i] = sum[i+1]+a[i];
        ans += a[i] & sum[i+1];
    }
    cout<<ans;
}