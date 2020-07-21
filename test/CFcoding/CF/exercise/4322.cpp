#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> t[10001];
int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n,k;cin>>n>>k;
    int tmp;
    for (int i=0;i<n;++i){
        for (int j=0;j<k;++j)
        {cin>>tmp;
        t[i].push_back(tmp);}
    }
    int sum;
    int res = 0;
    for (int i=0; i<n;++i){
        for (int j=i+1; j<n;++j){
            int s;
            sum = t[i][0] + t[j][0];
            for (s=1;s<k;++s){
                if (t[i][s] + t[j][s] != sum) break;
            }
            if (s == k-1) res++;
        }
    }
    cout<<res;

}