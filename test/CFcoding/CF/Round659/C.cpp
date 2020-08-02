//
// Created by hsh on 2020/7/24.
//

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
int counts[21][21];
using namespace std;

int main(){
    int t;cin>>t;
    while (t--){
        memset(counts,0, sizeof(counts));
        int n;cin>>n;
        string a,b;
        cin>>a>>b;
        bool flg = true;
        for (int i=0;i<n;++i){
            if (a[i] > b[i]) {flg=false;break;}
            counts[ a[i]-'a' ][ b[i]-'a' ]++;
        }
        if (!flg) {cout<<-1<<endl;continue;}
        int res = 0;

        for (int l=0;l<20;++l){
            for (int r=l+1;r<20;++r) {
                if (counts[l][r]){
                    res++;
                    for (int i=r+1;i<20;++i){
                        counts[r][i] += counts[l][i];
                        counts[l][i] = 0;
                    }
                    break;
                }
            }
        }
        cout<<res<<endl;

    }
}