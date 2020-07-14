//
// Created by hsh on 2020/7/4.
//

#include <iostream>

using namespace std;

int main(){
    int cases;
    cin>>cases;
    int data;
    while(cases--) {
        bool flag=true;
        int m,n;
        cin>>m>>n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int judge = 0;
                if (i > 0) ++judge;
                if (i < m-1) ++judge;
                if (j > 0) ++judge;
                if (j < n-1) ++judge;
                cin >> data;
                if (data > judge) {
                    flag=false;
                }
            }}
        if (flag){
        cout << "Yes\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int judge = 0;
                if (i > 0) ++judge;
                if (i < m-1) ++judge;
                if (j > 0) ++judge;
                if (j < n-1) ++judge;
                cout << judge << " ";
            }
            cout << endl;
        }}
        else {cout << "No\n";}

    }
    return 0;
}