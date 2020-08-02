//
// Created by hsh on 2020/7/31.
//

#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
int mo = 1e9+7;
int power(int x, int m){
    int nowpow = 1;
    while(m){
        if (m&1) nowpow = 1ll * nowpow * x % mo;
        x = 1ll * x * x % mo;
        m>>=1;
    }
    return nowpow;
}

int main(){
    int n;cin>>n;
    int res =  1ll * n  *  power(2,n-1)   % mo;
    cout<<res;
    return 0;
}