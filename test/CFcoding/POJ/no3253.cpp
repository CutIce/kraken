//
// Created by hsh on 2020/7/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

// timeout version:
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int res=0;
    int tmp;
    while(a.size()>1){
        tmp = a[0]+a[1];
        res+=tmp;
        a.erase(a.begin());
        a.erase(a.begin());
        bool flag=false;
        for (int i=0;i<a.size();++i)
            if (a[i]>tmp) {a.insert(a.begin()+i,tmp);flag=true;}
        if (!flag) a.push_back(tmp);

    }
    cout<<res<<endl;
}