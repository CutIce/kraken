#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int a[1000001];
int main(){
    int n;cin>>n;
    for (int i=0; i<n; ++i) {cin>>a[i];}
//    int i=0,j=n-1;
//    for (i;a[i] <=0 && i<n ;++i);
//    for (j;a[j] <= 0 && j>=0; --j);
//
//    for (i;a[i]+a[i+1] <= 0 && i<j-1 ; ++i);
//    for (j;a[j]+a[j-1] <= 0 && j>i ; --j);
//
//    long res = 0;
//    long ans = 0;
//    for (int k=i;k+1<=j;k+=2){
//        ans +=a[k]+a[k+1];
//        if (ans < 0) ans = 0;
//        res = max(res, ans);
//    }
//    ans =0;
//    for (int k=j;k-1>=i;k-=2){
//        ans +=a[k]+a[k-1];
//        if (ans < 0) ans = 0;
//        res = max(res, ans);
//    }
    long res = 0;
    long ans = 0;
    for (int i=0; i<n-1;i+=2){
        ans += a[i]+a[i+1];
        res = max(res , ans);
        if (ans <0) ans = 0;
    }
    ans = 0;
    for (int i=1; i<n-1;i+=2){
        ans += a[i]+a[i+1];
        res = max(res , ans);
        if (ans <0) ans = 0;
    }

    ans = 0;
    for (int i=3; i<n-1;i+=2){
        ans += a[i]+a[i+1];
        res = max(res , ans);
        if (ans <0) ans = 0;
    }
//    ans = 0;
//    for (int i=n-1; i>=1;i-=2){
//        ans += a[i]+a[i-1];
//        res = max(res , ans);
//        if (ans <0) ans = 0;
//    }
//    ans = 0;
//    for (int i=n-1; i>=1;i-=2){
//        ans += a[i]+a[i-1];
//        res = max(res , ans);
//        if (ans <0) ans = 0;
//    }
//    cout<<res;
    return 0;
}