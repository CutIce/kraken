#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;cin>>n;
    if (n == 0) {cout<<0; return 0;}
    stack<int> s;
    int *data = new int [n];
    for (int i=0;i<n;++i)
        cin>>data[i];
    s.push(0);
    int i=1, res=0;
    while(i < n){
        if (s.empty()) s.push(i++);
        else {
        if (data[i] > data [s.top()] ) s.push(i++);
        else if (data[i] == data[s.top()]) {
            bool flag = true;
            for (int j=s.top(); j<i;++j){if (data[j] > data[i]) flag = false;}
            if (!flag) s.push(i);
            else ++i;}
        else {
            int indexnow = s.top();s.pop();
            int height = data[indexnow], rect = 0;
            if (s.empty()) {rect = height * i ;}
            else {
                int last = s.top();
                while(!s.empty() && data[s.top()] == height) {s.pop();last = s.top();}
                if (s.empty()) {rect = height*i; last = s.top();}
                else rect = height * (i - last - 1);}
            res = (rect > res ) ? rect : res;
        }
        }
    }
    while(!s.empty()){
        int indexnow = s.top(), height = data[indexnow];
        int rect = 0;
        s.pop();
        if (!s.empty()){rect = (n -s.top() -1) * height;}
        else {rect = n*height;}
        res = (rect > res ) ? rect : res;
    }
    cout<<res;
    delete [] data;
    return 0;
}

//            if (s.empty())  {rect = height * i;}
//            else {rect = height * (i - s.top() -1);}
//            res = (rect > res ) ? rect : res;
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        if (n == 0) return 0;
        int *data = new int [n];
        for (int i=0;i<n;++i)
            data[i] = heights[i];;
        s.push(0);
        int i=1, res=0;
        while(i < n){
            if (s.empty()) s.push(i++);
            else {
            if (data[i] > data [s.top()] ) s.push(i++);
            else if (data[i] == data[s.top()]) {
            bool flag = true;
            for (int j=s.top(); j<i;++j){if (data[j] > data[i]) flag = false;}
            if (!flag) s.push(i);
            else ++i;}
            else {
                int indexnow = s.top();s.pop();
                int height = data[indexnow], rect = 0;
                if (s.empty()) {rect = height * i ;}
                else {
                                    int last = s.top();
                while(!s.empty() && data[s.top()] == height) {s.pop();last = s.top();}
                if (s.empty()) {rect = height*i; last = s.top();}
                else rect = height * (i - last - 1);}
                res = (rect > res ) ? rect : res;
                }
                res = (rect > res ) ? rect : res;
            }}
        while(!s.empty()){
            int indexnow = s.top(), height = data[indexnow];
            int rect = 0;
            s.pop();
            if (!s.empty()){rect = (n -s.top() -1) * height;}
            else {rect = n*height;}
            res = (rect > res ) ? rect : res;
        }
        return res;
        }
};*/