////
//// Created by hsh on 2020/7/16.
////
//
//// 单调栈：
//
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    int n;cin>>n;
//    vector<int> a(n+1);
//    a[n] = 0;
//    for (int i=0;i<n;++i) cin>>a[i];
//    stack<int > s;
//    vector<int> left(n+1);
//    vector<int> right(n+1);
//    long res = 0;
//    for (int i=0; i<=n; ++i){
//        while (!s.empty() && a[s.top()] >= a[i]){
//            right[s.top()] = i;
//            s.pop();
//        }
//        left[i] = s.empty() ? -1 : s.top();
//        s.push(i);
//    }
//    for (int i=0; i<n; ++i)
//        res = max(res , (long)a[i] * (right[i] - left[i] -1) );
//    cout<<res;
//}


// 单调队列

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
//    vector<int> a(n);
//    for(int i=0;i<n;++i) cin>>a[i];
    deque<int> incre;
    deque<int> decre;
    queue<int> q;
    int ans = 0;
    int now;
    for (int i =0; i<n; ++i){
        cin>>now;
        q.push(now);
        while(!incre.empty() && incre.back() > now ) incre.pop_back();
        incre.push_back(now);
        while (!decre.empty() && decre.back() < now ) decre.pop_back();
        decre.push_back(now);


        while ((decre.front() - incre.front()) > k ){
            if (!q.empty()){
                if (q.front() == incre.front()) incre.pop_front();
                if (q.front() == decre.front()) decre.pop_front();
                q.pop();}
            else break;}
        int res = q.size();
        ans = max(res , ans);
        }
        cout<<ans;
    return 0;
}