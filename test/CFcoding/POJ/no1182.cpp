//
// Created by hsh on 2020/7/11.
//

#include <iostream>
#include <vector>

using namespace std;
int par[50005];
int rank[50005];
int visited[50005]
void init(int n){
    for (int i=0;i<n;++i)
    {par[i]=i;
    rank[i]=0;
    visited[i]=0;
    }
}

int find(int x){
    while(par[x] != x )
        x = par[x];
    return x;
}

void unite(int x, int y){
    x = find(x);
    y = find(y);

    if (x == y) return ;

    if (rank[x] < rank[y]){
        par[x] = y;}
    else {
        par[y] = x;
        if (rank[x] == rank [y] ) ++rank[x];
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}

int main(){
    int n,k,x,y,d;
    int counts = 0;
    cin>>n>>k;
    init(n+1);
    while(k--){
        cin>>d>>x>>y;
        if (x < 0 || x > n || y < 0 || y > n  )
            counts++;
        if (d==1){
            if ( ! same(x,y) ){
                if ( visited[x]==0 || visited[y]==0 ) {unite(x,y);visited[x]=1;visited[y]=1;}
                else {counts++;
                    continue;}}
            continue;
        }
        else {

        }
    }
}