//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main(){
//    int n;cin>>n;
//    stack<int> s;
//    long *data = new long [n];
//    for (int i=0;i<n;++i)
//        cin>>data[i];
//    s.push(-1);
//    long res = 0;
//    for (int i=0;i<=n;++i){
//        long h,rect = 0;
//        h = (i < n) ? data[i] : 0;
//        while(s.top()!= -1 && data[s.top()] > h){
//            int index = s.top();s.pop();
//            while(s.top()!= -1 && data[s.top()] == data[index]) {index=s.top();s.pop();}
//            rect = data[index] * ( i - s.top() -1);
//            res = (res > rect) ? res : rect;
//        }
//        s.push(i);
//    }
//    cout<<res;
//    delete [] data;
//    return 0;
//}

//            if (s.empty())  {rect = height * i;}
//            else {rect = height * (i - s.top() -1);}
//            res = (rect > res ) ? rect : res;
/*
class Solution {
public:
    long largestRectangleArea(vector<long>& data) {
        long n=data.size();
        stack<long> s;
        if (n == 0) return 0;
        long *data = new long [n];
        for (long i=0;i<n;++i)
            data[i] = data[i];;
        s.push(0);
        long i=1, res=0;
        while(i < n){
            if (s.empty()) s.push(i++);
            else {
            if (data[i] > data [s.top()] ) s.push(i++);
            else if (data[i] == data[s.top()]) {
            bool flag = true;
            for (long j=s.top(); j<i;++j){if (data[j] > data[i]) flag = false;}
            if (!flag) s.push(i);
            else ++i;}
            else {
                long indexnow = s.top();s.pop();
                long height = data[indexnow], rect = 0;
                if (s.empty()) {rect = height * i ;}
                else {
                                    long last = s.top();
                while(!s.empty() && data[s.top()] == height) {s.pop();last = s.top();}
                if (s.empty()) {rect = height*i; last = s.top();}
                else rect = height * (i - last - 1);}
                res = (rect > res ) ? rect : res;
                }
                res = (rect > res ) ? rect : res;
            }}
        while(!s.empty()){
            long indexnow = s.top(), height = data[indexnow];
            long rect = 0;
            s.pop();
            if (!s.empty()){rect = (n -s.top() -1) * height;}
            else {rect = n*height;}
            res = (rect > res ) ? rect : res;
        }
        return res;
        }
};*/

// 4ms example:
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;cin>>n;
    long *data = new long [n];
    for (int i=0;i<n;++i)
        cin>>data[i];
    stack<int> s;
    vector<int>left(n),right(n);
    for(int i=0;i<n;i++){
        while(! s.empty()&& data[s.top()]>=data[i]){
            right[ s.top()]=i;
            s.pop();
        }
        left[i]=( s.empty()?-1: s.top());
        s.push(i);
    }
    long res=0;
    for(int i=0;i<n;i++){
        long rect = (right[i]-left[i]-1)*data[i];
        res= res > rect ? res : rect;
    }
    cout<<res;
}