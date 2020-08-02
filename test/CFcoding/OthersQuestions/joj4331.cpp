//
// Created by hsh on 2020/7/24.
//

#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <stack>

using  namespace std;

int main(){
    int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
    int tmp;
    int n;
    cin>>n;
    cin>>x1>>y1>>x2>>y2;
    for (int i=1;i<n;++i){
        cin>>tmp;if (tmp<x1) x1=tmp;
        cin>>tmp;if (tmp<y1) y1=tmp;
        cin>>tmp;if (tmp>x2) x2=tmp;
        cin>>tmp;if (tmp>y2) y2=tmp;
    }
    long res = (long)(x2-x1) * (long)(y2-y1);
    cout<<res;
    return  0;
}