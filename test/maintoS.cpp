/*
#include <iostream>
#include <iomanip>
using namespace std;

double bonus[6]={5000000.0,212024.0,3000.0,200.0,10.0,5.0};  // 定义各奖项的奖金数额
double expect[15]={0};  // save the expect
double s[15]={0};       // save the sum of p

double f(int n){  // 求阶乘
    if (n==0) return 1.0;
    double res=1;
    for (double i=1;i<=n;++i)
        res*=i;
    return res;
}
double c(int p,int q){  // 求组合数
    double r1=f(p),r2=f(q-p),r3=f(q);
    double res=r3/r1/r2;
    return r3/r1/r2;
}

void  print(int m){    // 计算概率、总概率、期望
    double p[6];
    double sum=0;
    double e=0;
    p[0]=c(m-6,27)/c(m,33)/16.0;
    p[1]=c(m-6,27)*15.0/c(m,33)/16.0;
    p[2]=c(m-5,27)*6.0/c(m,33)/16.0;
    p[3]=(6.0*c(m-4,27)*15.0+15.0*c(m-4,27))/c(m,33)/16.0;
    p[4]=(15*c(m-4,27)*15.0+20.0*c(m-3,27))/(c(m,33)*16.0);
    p[5]=(15*c(m-2,27)+6.0*c(m-1,27)+c(m,27))/c(m,33)/16.0;

    for (int i=0;i<6;++i) {  //  输出概率
        sum+=p[i];
        e+=p[i]*bonus[i];
        cout << fixed << setprecision(9) << p[i] << '\t';
    }
    expect[m-6]=e;          // 计算期望
    s[m-6]=sum;             // 计算总概率
    cout<<endl;
}
int main (){
    int m=6;
    cout<<'\t'<<"the 1 prize"<<'\t'<<"the 2 prize"<<'\t'<<"the 2 prize"<<'\t'<<"the 4 prize"<<'\t'<<"the 5 prize"<<'\t'<<"the 6 prize"<<endl;
    cout<<endl;  // 输出各奖概率
    for (;m<=20;++m)
    {   cout<<"m="<<m<<'\t';
        print(m);}


    cout<<endl<<endl<<endl;  // 输出总概率与期望
    cout<<"m"<<'\t'<<"The sum of P:"<<'\t'<<"The Expect"<<'\t'<<endl;;
        for (int i=0;i<15;++i)
            cout<<"m="<<i+6<<'\t'<<s[i]<<'\t'<<expect[i]<<endl;


    cout<<endl<<"m"<<'\t'<<"the expect over consume:"<<endl;
    for (int i=6;i<=20;++i) {
        double consume= c(6, i);
        cout<<"m="<<i<<'\t';
        cout<<expect[i-6]/consume/2<<endl;
    }
*/
/*    double r1,r2,r3=c(6,33);
    double res=0.0;
    for (int i=0;i<=6;++i){
        r1=c(i,17);r2=c(6-i,16);
        res=r1*r2/r3;
        cout<<res<<endl;
    }*//*



}
*/

#include <iostream>
#include <math.h>
using  namespace std;

/*struct node{
    int x;
    node *n;
    node (int x1=0,node *p= nullptr){x=x1,n=p;}
};*/

int main(){
/*    node x1(1, nullptr),x2(2, &x1);
    x1.n=&x2;
    node *p=&x1;

    cout<<p->x<<endl;
    cout<<p->n->x<<endl;
    return 0;*/

/*    int a[4][5]= {{10, 11, 12, 13, 14},
                  {20, 21, 22, 23, 24},
                  {30, 31, 32, 33, 34},
                  {40, 41, 42, 43, 44}};
    int i=1,j=3;
    cout<<"A"<<" "<<*(a[i]+j)<<endl;
    cout<<"B "<<*(*(a+i)+j)<<endl;
    cout<<"C "<<(*(a+i))[j]<<endl;
    cout<<"D "<<*(a+5*i+j)<<endl;*/

    /*char ch[2];
    ch[0]='a';ch[1]='a';
    while (ch[1]!='\0'){
        cin>>ch[1];
        if (ch[1]<='9' && ch[1]>='0')
            continue;
        else if (ch[0]<='9' && ch[0]>='0')
            cout<<endl<<ch[1];
        else cout<<ch[1];
        ch[0]=ch[1];
    }*/
    /*char ch1,ch2;
    cin>>ch1>>ch2;
    cout<<ch1<<ch2;*/

    double r[14]={  ,  ,   ,   ,   ,   ,   ,   ,   ,   ,   ,   ,   ,     };  y
    double t[14]={20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80 ,85};

    double x[14];  // x
    double x_=0.0,y_=0.0;
    double b;
    double multi=0.0;
    double sigemaX2=0.0;
    for (int i=0;i<14;++i){
        x[i]=1/t[i];
        y[i]=log(r[i]);
        x_+=x[i],y_+=y[i];
        multi+=x[i]*y[i];
        sigemaX2+=x[i]*x[i];
    }
    x_/=14.0,y_/=14.0;
    b=(multi-14*x_*y_)/(sigemaX2-14*x_*x_);
    double lnA=y_-b*x_;
    cout<<"y="<<b<<"(1/T)+"<<lnA<<endl;
}

    /*char ch1,ch2;
    while (true) {
        cin>>ch2;
        if (ch2<)
    }*/


/*
 /*
#include <iostream>
using namespace std;

int main() {
*/
/*    double data30[5]={13.23  ,  13.25  ,  13.28  ,  13.23  ,  13.22};
    double data35[5]={9.40  ,  9.22  ,  9.23  ,  9.00  ,  9.03};
    double data40[5]={6.45  ,  6.52  ,  6.53  ,  6.52  ,  6.54};
    double data45[5]={4.83  ,  4.97  ,  4.78  ,  4.74  ,  4.78};
    double data50[5]={3.62  ,  3.55  ,  3.60  ,  3.82  ,  3.56};
    double data55[5]={2.79  ,  2.64  ,  2.83  ,  2.84  ,  2.81};*//*


    double l=0.300;
    double p=7800.0  ,   p0=950.0  ,  D=0.02  ,  d=0.0;
    double dl[8]={ 0.001493   ,   0.001494   ,   0.001483   ,   0.001460    ,  0.001521   ,  0.001470   ,  0.001491   ,   0.001501};
    double re[7]={0.0};
    for (int i=0;i<8;++i)
        d+=dl[i];
    d/=8.0;
    d=0.001490;

    double truedata[7]={0.6210  ,  0.4510  ,  0.3120  ,  0.2310  ,   0.160964    ,        0.121224   ,         0.092905};

    */
/*double data[7][5]={     {19.00  ,  19.0  ,  19.0  ,  19.0  ,  19.0 }  ,
                            {13.23  ,  13.25  ,  13.28  ,  13.23  ,  13.22}  ,
                            {9.40  ,  9.22  ,  9.23  ,  9.00  ,  9.03}  ,
                            {6.45  ,  6.52  ,  6.53  ,  6.52  ,  6.54}  ,
                            {4.83  ,  4.97  ,  4.78  ,  4.74  ,  4.78}  ,
                            {3.62  ,  3.55  ,  3.60  ,  3.82  ,  3.56}  ,
                            {2.79  ,  2.64  ,  2.83  ,  2.84  ,  2.81}};*//*

    */
/*double data[7][5]={     {20.13  ,  19.17  ,  19.45  ,  19.18  ,  19.46 }  ,
                            {13.25  ,  12.98  ,  13.29  ,  12.84  ,  13.31}  ,
                            {9.24  ,  9.23  ,  9.31  ,  9.42  ,  9.23}  ,
                            {6.67  ,  6.21  ,  6.54  ,  6.55  ,  6.54}  ,
                            {4.80  ,  4.48  ,  4.78  ,  4.79  ,  4.81}  ,
                            {3.63  ,  3.63  ,  3.60  ,  3.63  ,  3.60}  ,
                            {2.87  ,  2.80  ,  2.82  ,  2.76  ,  2.83}};*//*

    */
/*double data[7][5]={     {23.14  ,  22.78  ,  23.56  ,  22.21  ,  22.60 }  ,
                            {16.23  ,  15.87  ,  16.25  ,  16.24  ,  13.31}  ,
                            {11.30  ,  11.27  ,  11.30  ,  11.29  ,  11.27}  ,
                            {7.98  , 7.96  ,  8.02  ,  8.03  ,  7.96}  ,
                            {5.84  ,  5.43  ,  5.83  ,  5.79  ,  5.86}  ,
                            {4.42  ,  4.38  ,  4.44  ,  4.41  ,  4.40}  ,
                            {3.46  ,  3.49  ,  3.42  ,  3.44  ,  3.44}};*//*

    double data[7][5]={     {27.62  ,  27.25  ,  28.09  ,  27.60  ,  28.05 }  ,
                            {19.50  ,  19.52  ,  19.53  ,  19.53  ,  19.59}  ,
                            {13.59  ,  13.57  ,  13.61  ,  13.18  ,  13.33}  ,
                            {9.64  ,  9.68  ,  9.65  ,  9.61  ,  9.64}  ,
                            {6.97  ,  7.08  ,  7.04  ,  6.98  ,  7.01}  ,
                            {5.31  ,  5.26  ,  5.26  ,  5.34  ,  5.29}  ,
                            {4.15  ,  4.17  ,  4.14  ,  4.09  ,  4.19}};
    double x[7]={0.0};  // 时间均值
    double v[7]={0.0};  // 速度
    double n[7]={0.0};  // 粘滞系数
    double n1[7]={0.0}; // 修正后的粘滞系数
    double u[7]={0.0};  // 相对误差

    for (int i=0;i<7;++i) {
        for (int j=0;j<5;++j)
        {   x[i]+=data[i][j];   }
        x[i]/=5.0;
        v[i]=l/x[i];
        n[i]=(p-p0)*9.8*d*d/18/v[i]/(1+2.4*d/D);
        re[i]=v[i]*d*p0/n[i];
        //n1[i]=n[i]-3*v[i]*d*p0/16;
        n1[i]=n[i]/(1+3*re[i]/16);
        u[i]=(n[i]-truedata[i])/truedata[i];
    }
    cout<<"d:"<<'\t'<<d<<endl;
    cout<<"mean time:"<<endl;
    for (int i=0;i<7;++i)  cout<<x[i]<<'\t';
    cout<<endl;
    cout<<"v:"<<endl;
    for (int i=0;i<7;++i)  cout<<v[i]<<'\t';
    cout<<endl;
    cout<<"re:"<<endl;
    for (int i=0;i<7;++i)  cout<<re[i]<<'\t';
    cout<<endl;
    cout<<"no modify n"<<endl;
    for (int i=0;i<7;++i)  cout<<n[i]<<'\t';
    cout<<endl;
    cout<<"modified n:"<<endl;
    for (int i=0;i<7;++i)  cout<<n1[i]<<'\t';
    cout<<endl;
    cout<<"true data:"<<endl;
    for (int i=0;i<7;++i)  cout<<truedata[i]<<'\t';
    cout<<endl;
    cout<<"uncertain u :"<<endl;
    for (int i=0;i<7;++i)  cout<<u[i]<<'\t';
 }

*/
/*d:      0.001481
mean time:
19.478  13.134  9.286   6.502   4.732   3.618   2.816
v:
0.010268        0.0152277       0.0215378       0.0307598       0.0422654       0.0552792       0.0710227
re:
0.0213569       0.0469713       0.0939656       0.19166 0.361857        0.618998        1.02179
no modify n
0.676436        0.45612 0.322486        0.225803        0.164334        0.125647        0.0977946
modified n:
0.673738        0.452138        0.316903        0.21797 0.153892        0.11258 0.082071
uncertain u :
0.0892686       0.0113528       0.033609        -0.022499       0.0209352       0.036483        0.0526301*/


#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node ( int &x , node *p = nullptr ){ data = x , next = p ;}
    node () { next = nullptr ; }
    //~node() { delete next; }
    ~node (){};
};


int main(){
    int m;
    cin>>m;
    node a1(m);
    cout<<a1.data<<"  ";
    cin>>m;
    node a2(m, & a1);

    cout<<a2.data<<endl;
    cout<<a2.next->data<<endl;

    return 0;

}
 */