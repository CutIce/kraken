//
// Created by hsh on 2020/7/23.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//map<vector<int> , int> f;
//const int N = 2002000;
//char a[N];
//int s[N][26];
//int n;
//
//int cost(int l ,int r, int c){
//    return (r - l + 1) - (s[r][c] - s[l-1][c]);
//}
//
//int dfs(int l ,int r, int c){
//    if (f.count({l , r, c})){
//        return f[{l, r, c}];
//    }
//    int &x = f[ {l , r, c}];
//    if (l == r){
//        return x = (c != a[l]);
//    }
//    x = 0x3f3f3f3f;
//    int mid = (l+r) >>1;
//    x = min(x,dfs(l,mid, c+1) + cost(mid+1, r, c));
//    x = min(x,dfs(mid+1, r, c+1) + cost(l, mid, c));
//    return x;
//}
//
//int main(){
//    int t;cin>>t;
//    while (t--){
//        cin>>n;
//        cin>>(a+1);
//        for (int i=1;i<=n;++i){
//            a[i] -='a';
//        }
//        for (int i=1; i<=n;++i){
//            for (int j = 0; j < 26; ++j)
//                s[i] [j] = s[i-1] [j] + (a[i] == j);
//        }
//        f.clear();
//        cout<<dfs(1,n,0)<<"\n";
//    }
//    return 0;
//}

int calc(const string &s, char c){
    int size = s.size();
    if (size == 1) return s[0] != c;
    int mid = size / 2;
    int cntl = calc(string(s.begin(), s.begin()+mid), c+1);
    cntl += size / 2 - count(s.begin()+mid, s.end(), c);
    int cntr = calc(string(s.begin()+mid, s.end()), c+1);
    cntr += size / 2 - count(s.begin(), s.begin()+mid, c);
    return min(cntl,cntr);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n ; cin>>n;
        string s;cin>>s;
        cout<<calc(s,'a')<<endl;
    }
    return 0;
}