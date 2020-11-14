//
// Created by hsh on 2020/8/5.
//

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
//class segtree{
//    int size;
//    vector<long long> sums;
//public:
//    void init(int n){
//        size = 1;
//        while (size<n) size*=2;
//        sums.assign(2*size, 0ll);
//    }
//    void update(int i,int x){
//
//    }
//
//    void sum(int l, int r){
//
//    }
//
//};

void quick_power(int a, int x, int mo){
    ll res = 1;
    while(x>0){
       if (x & 1)  res = res * a %mo;
       a = a*a %mo;
       x>>=1;
    }
    cout<<res<<endl;
}

int main(){
    int a=2,x = 1e9+7, mo = 1e9+7;
    //cout<<x<<" "<<mo<<endl;
    //quick_power(a,x,mo);
    quick_power(3,3,5);
    return 0;

}