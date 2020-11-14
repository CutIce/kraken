/*
//
// Created by hsh on 2020/8/8.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <utility>
#include <string.h>
#include <math.h>
using namespace std;

int pri[170]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,
              157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,
              331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,
              509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,
              709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,
              919,929,937,941,947,953,967,971,977,983,991,997,1009,1013};
//bool used[500001];
int d[500001];
int res[500001];
int n,m;

int max_true_factor(int x){
    int y = sqrt(double(x))+1;
    if (x== 0 || x == 1 || x== 2 || x == 3) return x;
    for (int i=0; i<170 && pri[i]<=y ;++i){
        if (x%pri[i] == 0) return pri[i];
    }
    return x;
}

void solve(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    cin>>n;
    fill(d,d+n,0);
    //fill(used,used+n,false);
    for (int i=0;i<n;++i) {cin>>d[i];res[i] = max_true_factor(d[i]);}
    cin>>m;
    int type;
    int l,r,x;
    for (int i=0;i<m;++i){
        cin>>type;
        if (type == 1){
            cin>>l>>r;
            //fill(used+l-1,used+r,true);
            fill(d+l-1,d+r,-1);
        }
        else{
            cin>>x;
            if (d[x-1] == -1) cout<<res[x-1]<<endl;
            else cout<<d[x-1]<<endl;
        }
    }
}

int main(){
    string s[4] ={
            "abc","def","ghi","jdk"
    };
    string a = s[1];
    string b = "xyz";
    cout<<"a: "<<a<<endl;
    cout<<"s[1]:"<<s[1]<<endl;
    s[1] = b;
    cout<<"a: "<<a<<endl;
    cout<<"s[1]:"<<s[1]<<endl;
}*/

#include <iostream>
#include <random>

using namespace std;
bool used[257];

int main(){
    fill(used,used+257,false);
    int count = 0;
    int num = 0;
    while(count < 256){
        uniform_int_distribution<int> x1(1,256);
        uniform_int_distribution<int> y1(1,256);
        int x = x1(1);
        
        int v1 = x + y;
        int v2 = abs(x-y);
        if (!used[x] && !used[y] && !used[v1] && !used[v2] ){
            used[x] = true;
            used[y] = true;
            used[v1]= true;
            used[v2]= true;
            count+=4;
            num++;
        }
    }
    cout<<num<<endl;
}