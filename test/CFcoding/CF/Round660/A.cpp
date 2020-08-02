#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>
#include <string.h>
#include <tuple>
#include <set>
#include <vector>
#include <map>

using namespace std;
bool pri[200020];
vector<int> near;
vector<int> prime;

void init(){
    for (int i=2;i<100001;++i) pri[i] = false;

    for (int i=2; i<100001;++i){
        if (pri[i] == false) {prime.push_back(i);}
        for (int j=2;j*i<100001;++j)
            pri[j*i] = true;
    }
    int size = prime.size();
    cout<<size<<endl;

    for (int i=0; i<prime.size();++i)
        cout<<prime[i]<<endl;
    for (int i=0;i < size && prime[i] < 448 ;++i){
        for (int j=i+1;j<size;++j) {
            if ( prime[i]*prime[j] < 200001 )
                near.push_back(prime[i]*prime[j]); }
    }
    sort(near.begin(), near.end());
    for (int i=0;i<3;++i)cout<<near[i]<<" ";
}

int main(){
//    init();
//    for (int i=0;i<near.size();++i)
//        cout<<near[i]<<endl;
    int cases;cin>>cases;
    while (cases -- ){
        int n;cin>>n;
        if (n<=30) cout<<"NO\n";
        else if (n==44) cout<<"YES\n"<<6<<" "<<7<<" "<<10<<" "<<21<<endl;
        else if (n==36) cout<<"YES\n"<<5<<" "<<6<<" "<<10<<" "<<15<<endl;
        else if (n==40) cout<<"YES\n"<<3<<" "<<6<<" "<<10<<" "<<21<<endl;
        else cout<<"YES\n"<<6<<" "<<10<<" "<<14<<" "<<n-30<<endl;
    }
    return 0;
}