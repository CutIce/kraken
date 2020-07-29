#include <iostream>
#include <algorithm>

using namespace std;
#define long long ll

ll Pw(ll a, ll b, ll p){
    ll v = 1;
    for (;b;) {
        if (b & 1) v = v * a % p;
        a = a * a % p;
        b >>= 1;
    }
}

int main(){

}

//欧几里得算法
long gcd(long a, long b){
    return b? gcd(b,a%b) : a;
}

// 扩展欧几里得算法
void exgcd(long a, long b, long &x, long &y, long &d){
    if (!b) x = 1, y = 0, d = a;
    else {
        exgcd(b, a%b, y, x, d);
        y -= a/b*x;
    }
}