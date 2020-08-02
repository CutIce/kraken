//
// Created by hsh on 2020/7/21.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
int f[4040];
int main(){
    int t;cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> data(2*n);
        vector<int> decre;
        vector<int> a,b;
        for (int i=0; i<2*n; ++i){
            cin>>data[i];
            f[i] = 0;
        }
        for (int i=0; i<2*n & i+1<2*n; ){
            int j=i+1;int num = 0;
            while(j<2*n && data[j] < data[i] ) ++j;
            num = j - i;
            decre.push_back(num);
            i += num;
        }
        f[0] = 1;
        for (int i = 0; i<decre.size(); ++i){
            int x = decre[i];
            for (int j=n; j>=x; --j){
                f[j] = max(f[j-x], f[j]);
            }
            f[x]++;
        }
        if (f[n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}