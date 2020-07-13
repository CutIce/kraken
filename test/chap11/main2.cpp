//
// Created by hsh on 2020/5/21.
//

#include "sort.h"
#include <math.h>
using  namespace std;

int main(){
    /*set<int,int> a[9]={{89,0},{21,0},
                       {114,0},{711,0},{5,0},{90,0},{212,0},
                       {16,0},{50,0}};*/
//    set<int,int> a[9]={{8,0},{1,0},
//                       {4,0},{7,0},{5,0},{9,0},{2,0},
//                       {6,0},{3,0}};

    float a[10]={37.79,	34.21,	31.55,	28.01,	25.41,	22.92,	20.76,	19.18,	16.79,13.23};
    float t[10]={0.729,	2.511,	4.282,	6.041,	7.889,	9.561	,11.324	,13.162,	14.977,	16.751};
    float res[10];
    float add=0.0,t_=0.0,y_=0.0;

    for (int i=0;i<10;++i){
        res[i]=log (a[i]);
        t_+=t[i];
        add+=res[i];
    }

    float b,upper=0.0,lower=0.0;
    for(int i=0;i<10;++i){
        y_+=res[i];
        upper+=t[i]*res[i];
        lower+=t[i]*t[i];
    }
    t_/=10.0;
    y_/=10.0;
    b=(upper-10*t_*y_)/(lower-10*t_*t_);


    cout<<"minus:"<<endl;
    for(int i=0;i<10;++i) cout<<a[i]<<" ";
    cout<<endl;
    cout<<"t:"<<endl;
    for(int i=0;i<10;++i) cout<<t[i]<<" ";
    cout<<endl;
    cout<<"y:"<<endl;
    for(int i=0;i<10;++i) cout<<res[i]<<" ";
    cout<<endl;


    cout<<"upper:"<<upper<<endl;
    cout<<"low:"<<lower<<endl;
    cout<<"t_:"<<t_<<endl;
    cout<<"y:"<<y_<<endl;
    cout<<b<<endl;

    float aver[10]={3.632,	3.532,	3.451,	3.332,	3.235	,3.132	,3.033,	2.953, 	2.820,	2.582};
    float avery=0.0;
    for(int i=0;i<10;++i) {avery+=aver[i];}
    avery/=10.0;
    cout<<avery;
    return 0;
}