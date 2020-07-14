////
//// Created by hsh on 2020/7/9.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    int cases;cin>>cases;
//    while(cases--){
//        int n;cin>>n;
//        vector<int> data(n);
//        vector<int> so(n+1);
//        for (int i=0;i<n+1;++i) so[i]=i;
//        for (int i=0;i<n;++i) {
//            cin>>data[i];
//            for (int j=0;j<so.size();++j){
//                if (so[j]==data[i])  {so.erase(so.begin()+j);}
//            }
//        }
//        int count=0;
//        for(int i=0;i<so.size();++i){
//            cout<<so[i]<<" ";
//        }
//        cout<<endl;
//        for (int i=0;i<so.size();++i){
//
//        }
//
//
//        }
//
//
//}

/**
 *    author:  tourist
 *    created: 04.07.2020 18:08:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> ret;
        while (n > 0) {
            vector<bool> was(n, false);
            for (int i = 0; i < n; i++) {
                if (a[i] < n) {
                    was[a[i]] = true;
                }
            }
            int mex = 0;
            while (mex < n && was[mex]) {
                ++mex;
            }
            if (mex == n) {
                ret.push_back(n - 1);
                a[n - 1] = mex;
                --n;
                continue;
            }
            ret.push_back(mex);
            a[mex] = mex;
        }
        cout << (int) ret.size() << '\n';
        for (int i = 0; i < (int) ret.size(); i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << ret[i] + 1;
        }
        cout << '\n';
    }
    return 0;
}

//v(n);
//sort(v.begin(),v.end())

