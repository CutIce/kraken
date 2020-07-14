//
// Created by hsh on 2020/7/14.
//
//
//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main(){
//    int k,n,res=0;
//    cin>>k>>n;
//    vector<int> data(n);
//    queue<int> increase;
//    queue<int> decrease;
//    for (int i=0;i<n;++i)
//        cin>>data[i];
//
//    }
//
//}
//#include <iostream>
//#include <queue>
//#include <deque>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    int k,n; cin>>k>>n;
//    int res=0;
//    vector<int> data(n);
//    queue<int> Q;
//    deque<int> Min,Max;
//    for( int j=0;j<n;j++){
//        cin>>data[j];
//    }
//    for(int i=0;i<n;i++){
//        Q.push(data[i]);
//        while(!Min.empty() && Min.back()>data[i])
//            Min.pop_back();
//        Min.push_back(data[i]);
//        while(!Max.empty() && Max.back()<data[i])
//            Max.pop_back();
//        Max.push_back(data[i]);
//
//        while((Max.front()-Min.front() )>k){
//            if(Q.empty())
//                break;
//            if(Q.front()==Min.front())
//                Min.pop_front();
//            if(Q.front()==Max.front())
//                Max.pop_front();
//            Q.pop();
//        }
//        res= res > Q.size() ? res : Q.size();
//    }
//    cout<<res;
//    return 0;
//}

#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
namespace DDQueue{
    queue<int> Q;
    deque<int> Min,Max;
    inline void push(int x){
        Q.push(x);
        while(!Min.empty() && Min.back()>x)
            Min.pop_back();
        Min.push_back(x);
        while(!Max.empty() && Max.back()<x)
            Max.pop_back();
        Max.push_back(x);
    }
    inline void pop(){
        if(Q.empty())
            return;
        if(Q.front()==Min.front())
            Min.pop_front();
        if(Q.front()==Max.front())
            Max.pop_front();
        Q.pop();
    }
    inline int get_ans(){
        return Max.front()-Min.front();
    }
    inline int size(){
        return Q.size();
    }
};

int main(){
    int k,n; std::cin>>k>>n;
    int *A = new int [n];
    register int i,ans=0;
    for(i=1;i<=n;i++){
        std::cin>>A[i];}
    for(i=1;i<=n;i++){
        DDQueue::push(A[i]);
        while(DDQueue::get_ans()>k)
            DDQueue::pop();
        ans=max(ans,DDQueue::size());
    }
    std::cout<<ans;
    delete [] A;
    return 0;
}


// version 3
//#include <iostream>
//#include <queue>
//#include <deque>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main(){
//    int k,n, res =0;
//    cin>>k>>n;
//    vector<int> data(n);
//    deque<int> increase;  // increase
//    deque<int> decrease;  // decrease
//    for (int i=0;i<n;++i){
//        cin>>data[i];
//        while(!increase.empty() && data[increase.back()] > data[i]) increase.pop_back();
//        increase.push_back(i);
//        while(!decrease.empty() && data[decrease.back()] < data[i] ) decrease.pop_back();
//        decrease.push_back(i);
//        int fi = increase.front(), fd = decrease.front();
//        while (data [fd] > data[fi] + k) {
//            if (fd < fi ) {decrease.pop_front();fd = decrease.front();}
//            else  {increase.pop_front();fi = increase.front();}
//        }
//        res = res > (abs(fd-fi)+1) ? res : (abs(fd-fi)+1) ;
//    }
//    cout<<res;
//    return 0;
//}


//#include <iostream>
//#include <deque>
//#include <algorithm>
//
//using namespace std;
//#define inf 0x7fffffff;
//int k,n,ans;
//
//int a[3000002],que1[3000002],que2[3000002];
//
//int main(){
//    cin>>k>>n;
//    for (int i=0;i<n;++i) cin>>a[i];
//    a[n+1] = inf;
//
//    int t=1,l1 = 1, l2 = 1, r1 =0, r2 =0;
//    for (int i=1; i<=n; ++i){
//        for (; l1<=r1 && a[que1[r1]] <= a[i]; --r1);
//        for (; l2<=r2 && a[que2[r2]] >= a[i]; --r2);
//        que1[++r1] = i; que2[++r2] =i;
//
//        for (; a[que1[l1]] - a[que1[l2]] >k ; t = que1[l1]<que2[l2] ? que1[l1++]+1:que2[l2++]+1);
//        ans = ans> (i-t+1) ? ans:(i-t+1);
//    }
//    cout<<ans;
//    return 0;
//}