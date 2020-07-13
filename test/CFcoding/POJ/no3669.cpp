//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;

//int data[303][303];
//bool is[303][303];
//int bfs(int x, int y, int time) {
//    ++time;
//    if (data[x][y] == 0 ) return time;
//    if (data[x][y] > time)
//
//}
//
//
//int main(){
//    int n,x,y,t;
//    cin>>n;
//    for (int i=0;i<303;++i){
//        for (int j=0;j<303;++j)
//            data[i][j] = 0;
//    }
//    for (int i=0;i<n;++i) {
//        cin>>x>>y>>t;
//        if (data[x][y] > t ) data[x][y]=t;
//        if ( x-1 > 0 ) {data[x-1,y] = (data[x-1][y] < t) ? data[x-1][y]:t ; }
//        if ( x+1 < 303 ) {data[x+1,y] = (data[x+1][y] < t) ? data[x+1][y]:t ; }
//        if ( y-1 > 0 ) {data[x,y-1] = (data[x][y-1] < t) ? data[x][y-1]:t ; }
//        if ( y+1 < 303 ) {data[x,y+1] = (data[x][y+1] < t) ? data[x][y+1]:t ; }
//    }
////    int safe=100000,safex,safey;
////    for (int i=0;i<303;++i){
////        for (int j=0;j<303;++j) {
////            if (data[i][j] < i + j + 1) ws[i][j] = false;
////            else {
////                is[i][j] = true;
////                if (i+j < safe) {safex=i,safey=j;}
////            }
////        }
//    int time=0,rs=0,ry=0;
//
//
//
//
//    }
//
//}


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct meteor{
    int x;
    int y;
    int t;
    p (int x1=0,int y1=0,int t1=10000): {
        x=x1;y=y1;t=t1;
    }
};


int main(){
    int n,x,y,t;
    meteor *meteors = new meteor [n];
    for (int i=0;i<n;++i){
        cin>>x>>y>>t;
        meteors[i].x = x;
        meteors[i].y = y;
        meteors[i].t = (meteors[i].t > t) ? ( t : meteors[i].t );

    }


    delete meteors [];
    return 0;
}