//
// Created by hsh on 2020/7/24.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;cin>>n;
    int a[1000000];
    for (int i=0; i<n;++i)
        cin>>a[i];
    int i=0;
    long res = 0;
    while(a[i]<=0) i++;
    long ans = 0 ;
    long plus = 0;
    for (int j=i;j+1<n;j +=2){
        plus = a[j]+a[j+1];
        ans = max(ans , ans + plus);
    }
    if (res < ans) res = ans;
    ans = 0;
    for (int j=i+1;j+1<n;j +=2){
        plus = a[j]+a[j+1];
        ans = max(ans , ans + plus);
    }
    if (res < ans) res = ans;
    cout<<res;
    return 0;
}