//
// Created by hsh on 2020/7/17.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


int main() {
    int x,y,z;
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>x>>y>>z;
        if (x!=y && y!=z && z!=x) {cout<<"No"<<endl;continue;}
        if (x==y && x>=z) {a=x; b=z;c=z; }
        else if (x==z && x>=y) {b=x; a=y; c=y;}
        else if (y==z && y>=x) {c=y;b=x,a=x;}
        //else if (x==y && x==z) {cout<<"Yes"<<endl<<x<<" "<<x<<" "<<x<<endl;continue;}
        else {cout<<"No"<<endl;continue;}
        cout<<"Yes"<<endl<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;

}