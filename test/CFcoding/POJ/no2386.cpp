//
// Created by hsh on 2020/7/10.
//

#include <iostream>
using namespace std;

char data[100][100] ;
int m,n;
bool dfs(int i, int j){
    if (i<0 || i>=m || j<0 || j>=n) return false;
    if (data[i][j] == '.') return false;
    if (data[i][j] == 'W') {
        data[i][j] = '.';
        dfs(i-1,j-1);
        dfs(i-1,j);
        dfs(i-1,j+1);
        dfs(i,j-1);
        dfs(i,j+1);
        dfs(i+1,j-1);
        dfs(i+1,j);
        dfs(i+1,j+1);
    }
    return true;
}

int main(){

    cin>>m>>n;
    char ch;


    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            cin>>ch;
            data[i][j] = ch;
        }
    }

    int count=0;

    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            if (dfs(i,j))  ++count;
        }
    }
    cout<<count;

}