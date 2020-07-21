//
// Created by hsh on 2020/7/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n+1),b(n+1),c(n+1);
//    for (int i=0; i<n; ++i){cin>>a[i];}
//    for (int i=0; i<n; ++i){cin>>b[i];}
//    for (int i=0; i<n; ++i) c[a[i]] = i;
//    for (int i=0; i<n; ++i) b[i] = c[b[i]];
//    a.assign(n,0);
//    for (int i=0; i <n; ++i){
//        a[(b[i]-i+n)%n]++;}
//
//    cout<<*max_element(a.begin(),a.end());
    int k=0;
    for (int i=1; i<=n; ++i){cin>>k;a[k] = i;}
    for (int i=1; i<=n; ++i){cin>>k;b[k] = i;}
    for (int i=1; i<=n;++i)
        c[(n+a[i]-b[i])%n]++;
    int ans=0;
    for (int i=0; i<=n;++i)
        ans=max(ans,c[i]);
    cout<<ans;
    return 0;
}