//
// Created by hsh on 2020/7/11.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

long lcm(long a, long b){
    long tmp,x1=a,x2=b;
    if (a < b) {
        tmp = a; a = b; b= tmp;
    }
    while(b != 0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return x1/a*x2;
}

int main(){
    int cases;cin>>cases;
    int n;
    while(cases--){
        int res1=0,res2=0;
        cin>>n;
        if ( n%2 ==0 ){
        res1=n/2;cout<<res1<<" "<<res1<<endl;}
        else {
            res1=1,res2=n-1;
            double sq = sqrt(double(n));
            int size = sq;
            bool flg =true;
            for (int i=3;i<sq+1 && flg; i+=2){
                if ( n%i ==0 )
                {res1 = n/i;res2 = n-res1;flg =false;}
            }
         cout<<res1<<" "<<res2<<endl;
        }
    }
}