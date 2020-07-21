//
// Created by hsh on 2020/7/15.
//

#include <iostream>
using namespace std;



int f(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n % 2 == 1) return n-1+2*f(n/2);
    else return n-1+f(n/2)+f(n/2+1);
}

int main(){

}