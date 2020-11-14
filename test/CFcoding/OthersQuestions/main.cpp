//
// Created by hsh on 2020/8/8.
//

//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
////#include <tuple>
//#include <map>
//#include <utility>
//#include <string.h>
//using namespace std;
//
//
//
//int d[16][16];
//int m,n;
//int flip[16][16];
//int times[16][16];
//int res;
//void init(){
//    res = 0;
//    memset(times,0, sizeof(times));
//    memset(flip,0, sizeof(flip));
//    memset(d,0, sizeof(d));
//    cin>>m>>n;
//    for (int i=0;i<m;++i){
//        for (int j=0;j<n;++j)
//            cin>>d[i][j];
//    }
//}
//int dx[5]={1,-1,0,0,0};
//int dy[5]={0,0,1,-1,0};
//void reverse(int i,int j){
//    for (int k=0;k<5;++k){
//        int xx = i + dx[k], yy = j + dy[k];
//        if (xx>=0 && xx<= m && yy>=0 && yy<= n){
//            flip[xx][yy]++;
//            flip[xx][yy] %=2;
//        }
//
//    }
//}
//
//void solve(){
//    for (int i=0;i<m-1;++i){
//        for (int j=0;j<n;++j){
//            if ( (d[i][j]+flip[i][j]) % 2 == 1){
//                res++;
//                reverse(i+1,j);
//                times[i+1][j]++;
//            }
//        }
//    }
//    bool flg = true;
//    for (int k=0;k<n;++k){
//        if ( (d[m-1][k] == 0 && flip[m-1][k] % 2 != 0) || (d[m-1][k] ==1 && flip[m-1][k] % 2 ==0)  )
//            flg =false;
//    }
//    if (!flg) cout<<"IMPOSSIBLE\n";
//    else {
//        for (int i=0;i<m;++i){
//            for (int j=0;j<n;++j){
//                cout<<times[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//    }
//}
//
//int main(){
//    init();
//    solve();
//    return 0;
//}


#include <stdio.h>
#include<cstring>
const int maxn = 20;
int M, N;
int color[maxn][maxn], cur[maxn][maxn];//题中读入颜色, 当前操作颜色(防止直接改变源颜色)
int oper[maxn][maxn], ans[maxn][maxn], steps = 0, minSteps = 1<<30; //当前操作, 最小操作, 当前解和最小解
void press(int x, int y)
{ //按下x, y处的按钮
    cur[x][y]^=1, cur[x+1][y]^=1, cur[x-1][y]^=1, cur[x][y+1]^=1, cur[x][y-1]^=1;
}
bool solve()
{ //判断是否已经解决问题
    memcpy(cur, color, sizeof(color));
    //根据枚举结果改变第一二行
    for(int i = 1; i <= N; i++)
        if(oper[1][i])
            press(1, i), steps++;
    //根据第i-1行决定第i行的操作
    for(int i = 2; i <= M; i++){
        for(int j = 1; j <= N; j++)
            if(cur[i-1][j])
                oper[i][j]=1, press(i, j), steps++;
    }
    //判断最后一行是否满足条件
    for(int i = 1; i <= N; i++)
        if(cur[M][i]) return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&M,&N);
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d",&color[i][j]);
    //仅仅枚举第一行的状态即可
    for(int i = 0; i < (1<<N); i++){ //状态压缩
        memset(oper, 0, sizeof(oper)), steps = 0; //初始化不要忘
        for(int j = 0; j < N; j++){
            oper[1][N-j] = (i>>j&1);
        }
        if(solve() && steps>0 && steps<minSteps)
            minSteps = steps, memcpy(ans, oper, sizeof(oper));;

    }
    if(minSteps < (1<<30))
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
    else printf("IMPOSSIBLE\n");
    return 0;
}