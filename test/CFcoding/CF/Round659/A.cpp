//
// Created by hsh on 2020/7/24.
//

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;++i) cin>>a[i];
        string s[101];
        s[0] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        char c = 'b';
        for (int i=0;i<n;++i){
            s[i+1] = s[i];
            s[i+1][a[i]] = c;
            c++;
            if (c > 'z') c='b';
        }
        for (int i=0;i<=n;++i)
            cout<<s[i]<<endl;
    }
    return 0;
}



//for (int i=0;i<n;++i) cin>>a[i];
//char c = 'a';
//int i=0;
//for (i=0;a[i]==0 &&i<n; ++i,++c)
//{s[i] += c;}
//++c;
//for (int k=0;k<a[i];++k) s[i]+=c;
//
//for (int j=i+1;j<n;++i,++c){
//if ()
//}





//for (int i=0;i<n;++i) {
//cin>>a[i];
//if (a[i] > maxnum){ maxindex=i;maxnuma[i];}
//}
//char c = 'a';
//if (maxnum == 0) {
//for (int i = 0; i < n; ++i, ++c) {
//cout << c << " ";
//}
//cout<<endl;
//continue;
//}