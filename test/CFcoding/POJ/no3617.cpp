//
// Created by hsh on 2020/7/10.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<char> ch(n);
    vector<char> res(0);
    for (int i=0;i<n;++i)
        cin>>ch[i];

    int a=0,b=n-1;
    while( a <= b){
        bool left = false;
        for (int i=0;a+i <= b;++i){
            if (ch[a+i] < ch[b-i]){left=true;break;}
            else if (ch[a+i] > ch [b-i] ) {left=false;break;}
        }
        if (left) res.push_back(ch[a++]);
        else res.push_back(ch[b--]);
    }
    int x=0;
    while (res.size()){
        if (x==80) {
            x=0;
            cout<<'\n';
            continue;}
        cout<<res[0];
        res.erase(res.begin());
        ++x;
    }
    return 0;
}