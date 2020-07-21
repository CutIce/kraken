#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int x[1000001];
int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n;cin>>n;
    if (n%2 ==0) x[1] = 1;
    else x[1] = 0;
    int res = x[1];
    for (int i=2; i<=n;++i){
        x[i] = i%2;
        for (int j=3;j<=n;++j){
            x[i] = x[i] ^ (i%j);
        }
        res = res ^ x[i];
    }
    cout<<res;
    return 0;
}