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

int main(){
    int cases;cin>>cases;
    while (cases--){
        int n;cin>>n;
        int m =( n + 3 ) / 4;
        for (int i=0;i<n-m;++i) cout<<9;
        for (int i=0;i<m;++i)   cout<<8;
        cout<<endl;
    }
    return 0;
}