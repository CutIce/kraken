#include<iostream>
#include<vector>
using namespace std;
int main(){
    int cases; cin >> cases;
    int num;
    int start,end;
    int judge=1;
    int j;
    int q;
    vector<int> data(1000);
    while (cases--){
        cin >> num;
        judge = 1;
        for (int i=0;i<num;i++) cin >> data[i];
        start = 0; end = num-1; q = num;
        while (judge){
            if (start == end) {judge = 0;break;}
            if (data[start] == q) {start++;q--;}
            else if (data[end] == q) {end--;q--;}
            else break;
        }
        if (judge){
            cout << "YES" << endl;
            for (int i = start;i<end+1;i++){if (data[i]==q) j=i;}
            cout << start+1 << ' ' << j+1 << ' ' << end+1 << endl;;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
