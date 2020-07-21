#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long a,b,c;
        long l,r,m;cin>>l>>r>>m;
        long sub = r - l;
        bool flag = true;

        for (int j=l; j<=r && flag ;j=r){
        for (int i=0;i<=sub && flag ; ++i){

                if ( (m+i)%j ==0 ) {
                    flag = false;
                    a = j;
                    b = l;
                    c = b+i;
                    break;
                }
                else if ((m-i) % j ==0){
                    flag = false;
                    a = j;
                    b = l+i;
                    c = l;
                    break;
                }
            }
        }
        cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    }
    return 0;
}
//int main(){
//    int t;cin>>t;
//    while(t--){
//        long a,b,c;
//        long l,r,m;
//        cin>>l>>r>>m;
//        long sub = r - l;
//        bool flag = true;
//        for (int j=l;j<=r && flag ;++j){
//            if (m<l) {
//                a = l;
//                long remain = m-l;
//                b = l;
//                c = 2*l -m;
//                flag = false;
//                break;
//            }
//            if (m%j ==0) {flag = false; a=j,b=c=l;break;}
//            long re = m%j;
//            long sub = r-l;
//            if ( re <= sub) {
//                a = j,c = l; b = c+re;
//                flag = false;
//            }
//            else if (re + sub >= j){  // re > sub
//                a = j ;
//                b = l ;
//                c = l + j - re;
//                flag = false;
//            }
//        }
//        cout<<a<<" "<<b<<" "<<c<<" "<<endl;
//    }
//    return 0;
//}