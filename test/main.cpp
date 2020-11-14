#include<iostream>
using namespace std;

int main()
{
    int s=0,n;
    int *num;
    cin>>s;

    int type,val;
    for(int i=0;i<s;++i){
        int stackstate=1,queuestate=1;
        cin>>n;
        num= new int[n+1];
        int head=0;
        int rear=0;//头部及尾部指针
        while(n--){
            cin>>type>>val;
            if(type==1) {num[rear]=val;++rear;}
            if(type==2){
                // judge queue state
               if (queuestate) {
                   if (val != num[head]) queuestate = 0;
                   ++head;
               }
               if (stackstate) {
                    if (val != num[rear-1]) stackstate = 0;
                    --rear;
               }
            }
            if(queuestate==0&&stackstate==0) break;
        }
        if(stackstate==1&&queuestate==1) cout<<"Both"<<endl;
        if(stackstate==1&&queuestate==0) cout<<"Stack"<<endl;
        if(stackstate==0&&queuestate==1) cout<<"Queue"<<endl;
        if(stackstate==0&&queuestate==0) cout<<"Error"<<endl;
        delete [] num;
    }
    return 0;
}