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
        string a;
        cin>>a;
        int res = 0;
        int n = a.size();
        for (char x='0'; x<='9'; ++x){
            for (char y='0';y<='9';++y){
                int cnt = 0;
                char c1 = x,c2 = y;
                for (int i=0; i<n; ++i){
                    if (a[i] == c1 ) {cnt++;swap(c1,c2);}
                }
                if (x == y)  res = max(res,cnt);
                else res = max(res, cnt&~1);
            }
        }
        cout<<a.size()-res<<endl;

    }
    return 0;
}