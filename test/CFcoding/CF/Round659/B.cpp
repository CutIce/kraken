//
// Created by hsh on 2020/7/24.
//

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <tuple>
using namespace std;
int n,k,l;
//set<tuple<int,int,bool>> mark;
//vector<int> a(10000,-100);
//bool go(int pos, int tide, bool down){
//    if ( pos > n ) return true;
//    if (mark.find({pos, tide, down}) != mark.end())
//        return false;
//    mark.insert({pos, tide, down});
//    tide += down ? -1 : 1;
//
//    if (tide == 0) down = false;
//    if (tide == k) down = true;
//
//    if (a[pos] + tide <= l && go(pos, tide, down))
//        return true;
//    if (a[pos+1] + tide <= l && go(pos+1, tide, down))
//        return true;
//    return false;
//}
//int main(){
//    int t;cin>>t;
//    while(t--){
//        cin>>n>>k>>l;
//        for (int i=0;i<n+10;++i) a[i] = -100;
//        for (int i=1;i<=n;++i) cin>>a[i];
//        if (go(0,0,false)) cout<<"YES\n";
//        else cout<<"NO\n";
//        mark.clear();
//    }
//    return 0;
//}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n >> k >> l;
        vector<int> safe={0};
        vector<int> d(n + 2);
        for (int i = 1; i <= n; ++i) {
            cin >> d[i];
            if (d[i] + k <= l)
                safe.push_back(i);
        }
        safe.push_back(n+1);
        bool ok = true;
        for (int i=1 ;i<safe.size() && ok ; ++i){
            int tide = k;bool down = true;
            for (int j = safe[i-1] +1; j<safe[i]; ++j){
                tide +=down ? -1 : 1;
                if (down) tide -= max(0,d[j] + tide - l);
                if (tide < 0 || d[j] + tide > l) {ok = false; break;}
                if (tide == 0) down = false;
            }
        }
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}