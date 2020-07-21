#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

long long a[1000001];
int main(){
    int n ; cin>>n;
    int res = 0;
    for (int i=0;i<n;++i){
        cin>>a[i];
        res = max(res , (int)a[i]);
    }
    cout<<res;
}