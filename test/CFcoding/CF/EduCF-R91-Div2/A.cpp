// created by hsh

#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(){
    int cases; cin >> cases;
    int num, j, start, end;
    int judge=1 , middle;
    vector<int> data(1000);
    while (cases--){
        cin >> num;
        judge = 1;
        for (int i=0;i<num;i++) cin >> data[i];
        start = 0; end = num-1; middle = num;
        while (judge){
            if (start == end) {judge = 0;break;}
            if (data[start] == middle) {start++;middle--;}
            else if (data[end] == middle) {end--;middle--;}
            else break;
        }
        if (judge){
            cout << "YES" << endl;
            for (int i = start;i<end+1;i++){if (data[i]==middle) j=i;}
            cout << start+1 << ' ' << j+1 << ' ' << end+1 << endl;;}
        else {cout << "NO" << endl;}
    }
    return 0;
}
