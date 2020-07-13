#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){
    int cases; cin >> cases;
    int num, min;
    int temp,index = 0;
    int person;
    int result = 0;
    while (cases--){
        result = 0; index = 0;
        cin >> num; cin >> min;
        vector<int> data(num);
        for (int i=0;i<num;i++) cin >> data[i];
        //cout << 1 << endl;
        sort(data.begin(), data.end());
       //cout << 1 << endl;
        while (index<num){
            if (min % data[index]==0) {person = min/data[index];index = index + person;}
            else {person = min/data[index]+1; index = index + person;}
            if (index<num) result++;
        }
        cout << result << endl;
    }
    return 0;
}