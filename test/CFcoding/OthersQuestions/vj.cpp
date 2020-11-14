//
// Created by hsh on 2020/8/7.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
//#include <tuple>
#include <map>
#include <utility>
#include <string.h>
using namespace std;
//typedef pair<string,string> group;
//
//group data[8]={
//        {"Data Structure","CHENTONG"},
//        {"Graph Theory", "CHENYUXUAN"},
//        {"Graph Theory", "SUNENZE"},
//        {"Dynamic Programming","ZHANGZHIQI" },
//        {"Dynamic Programming","LILUOXUAN" },
//        {"String","CHENWEIHZE"},
//        {"Math","LIBONING"},
//        {"Geometry, Search and Miscellaneous","GUYI"},
//};
//
//int main(){
//    string res="";
//    string in;cin>>in;
//    bool flg = true;
//    int i,j,k;
//    for (i=0;i<8 && flg;++i){
//        k=0;
//        for (j=0; k<data[i].second.size() ;){
//            for (k=0;k<data[i].second.size();){
//                if (in[j] == data[i].second[k]) {++j,++k;}
//                else ++k;
//            }
//            if (j==in.size()) {flg = false; res = data[i].first;}
//        }
//    }
//    cout<<res;
//}
//
//int main(){
//    string  a,b;cin>>a>>b;
//    cout<<a;
//    return 0;
//}

//char d[9][9];
//bool used[10];
//int n,k;
//int num;
//
//void next(int x,int y, int t){
//    if (t == k) {num++;
//        return;}
//    for (int i=x+1;i<n;++i){
//        for (int j=0;j<n;++j){
//            if (d[i][j] == '#' && !used[j]) {
//                used[j] = true;
//                next(i,j,t+1);
//                used[j] = false;
//            }
//        }
//    }
//}
//
//int main(){
//
//    while(cin>>n>>k){
//        if (k==-1 && n==-1) break;
//        memset(used,false, sizeof(used));
//        memset(d,'.',sizeof(d));
//        num = 0;
//        for (int i=0;i<n;++i)
//            for (int j=0;j<n;++j) cin>>d[i][j];
//        next(-1,0,0);
//        cout<<num<<endl;
//    }
//    return 0;
//}
//
//int dungeon[30][30][30];
//int reachable[30][30][30];
//int l,r,c,res;
//int sx,sy,sz;
//int ex,ey,ez;
//
//int dl[6] = {1,-1,0,0,0,0};
//int dr[6] = {0,0,1,-1,0,0};
//int dc[6] = {0,0,0,0,1,-1};
//char ch;
//void init(){
//    res = 0,sx=0,sy=0,sz=0,ex=0,ey=0,ez=0;
//    for (int i=0;i<l;++i){
//        for (int j=0;j<r;++j){
//            for (int k=0;k<c;++k){
//                cin>>ch;
//                if (ch == '.')      dungeon[i][j][k] = 1;
//                else if (ch =='S') {dungeon[i][j][k] = 1;sx=i;sy=j,sz=k;}
//                else if (ch =='E') {dungeon[i][j][k] = 1;ex=i;ey=j,ez=k;}
//                else dungeon[i][j][k] = 0;
//                reachable[i][j][k] = 0;
//            }
//        }
//    }
//}
//struct point {int x,y,z;
//    point(int a,int b,int c):x(a),y(b),z(c){}
//};
//
//
//void search_for_path(int sx,int sy,int sz){
//    reachable[sx][sy][sz] = 0;
//    queue<point> que;
//    que.push(point(sx,sy,sz));
//    bool flg = false;
//    while(!que.empty() ){
//        int size = que.size();
//        for(int i=0;i<size;++i) {
//            point p = que.front();que.pop();
//            for (int i=0;i<6;++i){
//                int xx = p.x + dl[i], yy = p.y + dr[i] , zz = p.z + dc[i];
//                if (xx < l && xx>=0 && yy < r && yy>=0 && zz < c && zz>=0 && reachable[xx][yy][zz] == 0 && dungeon [xx][yy][zz] == 1){
//                reachable[xx][yy][zz] =  reachable[p.x][p.y][p.z]+1;
//                que.push(point(xx,yy,zz));
//                }
//            }
//        }
//        ++res;
//    }
//}
//
//void show(){
//    std::ios::sync_with_stdio(false); std::cin.tie(0);
//    for (int i=0;i<l;++i){
//        for (int j=0;j<r;++j){
//            for (int k=0;k<c;++k)
//                cout<<reachable[i][j][k]<<"-";
//            cout<<endl<<endl;
//        }
//        cout<<endl<<endl;
//    }
//    cout<<endl;
//}
//
//int main(){
//    while(cin>>l>>r>>c){
//        if (l==0 && r==0 && c==0) break;
//        init();
//        search_for_path(sx,sy,sz);
//
//       //show();
//
//        if ( reachable[ex][ey][ez])
//            cout<<"Escaped in "<<reachable[ex][ey][ez]<<" minute(s).\n";
//        else cout<<"Trapped!\n";
//    }
//    return 0;
//}


//int n,k;
//int is[100001];
//int res;
/*void opera(int x){
    if (is[k] != 0) return;
    int l = res++;
    if (2*x < 100001 && is[2*x]==0) {is[2*x] = res;opera(2*x);}
    res = l;
    if (x-1>=0 && is[x-1] == 0){ is[x-1] = res;opera(x-1); }
    res = l;
    if (x+1 < 100001 && is[x+1] == 0) {is[x+1] = res;opera(x+1);}
}*/

//int main(){
//    fill(is,is+100001,0);
//    res = 0;
//    cin>>n>>k;
//    if (n>=k) {cout<<n-k;
//        return 0;}
////    for (int i=0;i<k;++i) cout<<is[i]<<" ";
//    is[n] = 0;
////    opera(n);
//    queue<int> que;
//    que.push(n);
//    while(is[k] == 0 && !que.empty()){
//        int size = que.size();
//        res++;
//        for (int i=0;i<size;++i) {
//            int v = que.front();que.pop();
//            int l = v - 1, m = v + 1, r = v * 2;
//            if (l <100001 && l>=0 && is[l] == 0) {is[l] = res;que.push(l);}
//            if (m <100001 && m>=0 && is[m] == 0) {is[m] = res;que.push(m);}
//            if (r <100001 && r>=0 && is[r] == 0) {is[r] = res;que.push(r);}
//        }
//    }
///*    for (int i=0;i<k;++i) cout<<is[i]<<" ";
//    cout<<endl;*/
//    cout<<is[k];
//    return 0;
//}


int d[16][16];
int m,n;
int flip[16][16];
int times[16][16];
int res;
void init(){
    res = 0;
    memset(times,0, sizeof(times));
    memset(flip,0, sizeof(flip));
    memset(d,0, sizeof(d));
    cin>>m>>n;
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j)
            cin>>d[i][j];
    }
}
int dx[5]={1,-1,0,0,0};
int dy[5]={0,0,1,-1,0};
void reverse(int i,int j){
    for (int k=0;k<5;++k){
        int xx = i + dx[k], yy = j + dy[k];
        if (xx>=0 && xx<= m && yy>=0 && yy<= n)
            flip[xx][yy]++;
    }
}

void solve(){
    for (int i=0;i<m-1;++i){
        for (int j=0;j<n;++j){
            if ( (d[i][j]+flip[i][j]) % 2 == 1){
                res++;
                reverse(i+1,j);
                times[i+1][j]++;
            }
        }
    }
    bool flg = true;
    for (int k=0;k<n;++k){
        if ( (d[m-1][k] == 0 && flip[m-1][k] % 2 != 0) || (d[m-1][k] ==1 && flip[m-1][k] % 2 ==0)  )
            flg =false;
    }
    if (!flg) cout<<"IMPOSSIBLE\n";
    else {
        for (int i=0;i<m;++i){
            for (int j=0;j<n;++j){
                cout<<times[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){
    init();
    solve();
    return 0;
}