//
// Created by hsh on 2020/7/5.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long cases;cin>>cases;
    long n;
    while (cases--){
        cin>>n;
        vector<long> data(n);
        for (int i=0;i<n;++i) cin>>data[i];
        if (data[0] < data[n-1]) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}