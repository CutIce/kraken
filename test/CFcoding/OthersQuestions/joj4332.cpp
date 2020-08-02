//
// Created by hsh on 2020/7/24.
//

#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;
//int main(){
//    int n;cin>>n;
//    int x = sqrt((double)n);
//    bool is[1000000];
//    int lcmn = 1;
//    for (int i=0;i<=n;++i) is[i] = true;
//    for (int i=2;i<=n ;++i){
//        if (is[i] == false) continue;
//        int num = 1;
//        int tem = n;
//        if (tem%i ==0){
//            while(tem % i ==0) {num*=i; tem/=i;}
//            for (int j=2; j*i <=n;++j)
//                is[j*i] =false;
//        }
//        else lcmn*=i;
//        lcmn *= num;
//    }
//    cout<<lcmn;
//    return 0;
//}
bool is[10000000];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;++i) is[i]= true;
    int x = sqrt(double(n));
    for (int i=2;i<=x;++i){
        for (int j=1;i*j<=n;++j) is[i*j] = false;
    }
    for (int i=n;i>=2;--i)
        if (is[i] == true) {cout<<2*i;break;}
    return 0;
}