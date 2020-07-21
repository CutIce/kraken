//
// Created by hsh on 2020/7/16.
//
// AC 7/16 16:40
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> like;
vector<int> onlya;
vector<int> onlyb;

int main(){
    int n, k = 0, t = 0, la = 0, lb = 0;
    cin>>n>>k;
    for (int i=0; i < n; ++i){
        cin>>t>>la>>lb;
        if (la == 1){
            if (lb == 1) like.push_back(t);
            else {onlya.push_back(t);
        }}
        else {
            if (lb == 1) onlyb.push_back(t);
        }
    }

    int lsize = like.size(), asize = onlya.size(), bsize = onlyb.size();
//
//    cout<<lsize<<" "<<asize<<" "<<bsize<<endl;
//
//    for (int i=0;i<lsize;++i)   cout<<like[i]<<" ";
//    cout<<endl;
//    for (int i=0;i<asize;++i)   cout<<onlya[i]<<" ";
//    cout<<endl;
//    for (int i=0;i<bsize;++i)   cout<<onlyb[i]<<" ";
//    cout<<endl;
    if ((lsize + asize < k) || (lsize + bsize < k )) {cout<<-1; return 0 ;}

    int res = 0;
    sort(like.begin(), like.end());
    sort(onlya.begin() , onlya.end());
    sort(onlyb.begin(), onlyb.end());

    int i=0,j=0,r=0; // i-a j-b k-l
    while(k--){
        if ((i==asize || j==bsize ) && r < lsize ){res += like[r++]; continue;}
        else if ((i < asize && j < bsize ) && r == lsize) {res  += onlya[i++] + onlyb[j++];continue;}
        if (onlya[i] + onlyb[j] < like[r]) {
            res += onlya[i++] + onlyb[j++];
        }
        else res += like[r++];
    }

    cout<<res;
}