#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <set>
#include <string.h>
#include <string>

using namespace std;


int main(){
    int cases;cin>>cases;
    while (cases--){
        int l, r, ans = 0;
        cin >>l>>r;
        if (r / l >= 2)
            cout<<l<<" "<<2*l<<endl;
        else cout<< -1<<" "<< -1<<endl;
    }
    return 0;
}






































