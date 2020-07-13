//
// Created by hsh on 2020/7/11.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int num=1;
    int cases;cin>>cases;
    while(cases--){
        vector<int> a(10);
        num=1; char ch;
        cin>>a[0];
        ch=cin.get();
        while( ch == ' '){
            cin>>a[num++];
            ch = cin.get();
            //cout<<a[num-1]<<ch<<"int:"<<(int)ch<<"over";
            cout<<a[num-1]<<ch<<"int:"<<(int)ch<<"!";
        }
        //cout<<"over"<<endl;

        if (  num % 2 ==0 ){
            int index=0 ;  // index refer to the minimum value between a[index+1 - a[index]
            int divide=10;
            for (int i=0;i<num-1;++i){
                if (a[i] == 0 ) continue;
                else if ( a[i+1] - a[i] < divide ) {index=i;divide = a[i+1]-a[i];}
            }
            int num1 = a[index+1],num2=a[index];
            a.erase(a.begin()+index,a.begin()+index+2);
            num-=2;
            int i=0,j=num-1;
            while( i<j ){
                num1=num1*10+a[i++];
                num2=num2*10+a[j--];
            }
            cout<<num1-num2<<endl;
        }
        else {
            int index=0,num1=0,num2=0;
            while(a[index] == 0) ++index;
            num1 = a[index];
            a.erase(a.begin()+index);
            int i=0,j=num-2;
            while(i<j){
                num1 = num1*10 +a[i++];
                num2 = num2*10 +a[j--];
            }
            cout<<num1-num2<<endl;
        }
    }
}

//int main(){
//    int n;cin>>n;
//     for (int i=0;i<n;++i) cin >> a[i];
//
//     a.erase(a.begin()+2,a.begin()+4);
//     for (int i=0;i<a.size();++i) cout<<a[i]<<" ";
//}

/*
2
0 1 2 4 6 7
0 1 2 3 4 5 6

 * */

//2
//0 1 2 4 6 7
//0 1 2 3 4 5 6 012467over
//
//012344
/*
 *
2
0 1 3 5 6 7 8 9
0 2 6 7 8 9

 26
 4

 */