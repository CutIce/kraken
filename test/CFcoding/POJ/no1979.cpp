//
// Created by hsh on 2020/7/10.
//

#include <iostream>
#include <vector>
using namespace std;
char data[20][20];
int w,h;
void dfs( int x,int y,int &counts){
    if ( x<0 || y<0 || x>=h || y>=w ) return;
    if (data [x][y] == '.' || data[x][y] =='@') {
        data[x][y] = '#';
        counts++;
        dfs(x+1,y,counts);
        dfs(x,y+1,counts);
        dfs(x,y-1,counts);
        dfs(x-1,y,counts);
        return;
    }
    if (data [x][y] =='#'){
        return;
    }
}

int main(){

    cin>>w>>h;
    int humanx,humany;
    while( w && h ){
        for (int i=0;i<h;++i) {
            for (int j=0;j<w;++j) {
                cin>>data[i][j];
                if (data[i][j] == '@') {humanx=i,humany=j;}
            }
        }
        int counts = 0;
        dfs(humanx,humany,counts);
        cout<<counts<<endl;
        cin>>w>>h;
    }
    return 0;
}