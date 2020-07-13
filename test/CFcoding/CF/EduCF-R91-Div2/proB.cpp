#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        string s;
        cin>>s;
        int size= s.size(), r = 0 , p = 0, s = 0;
        for (int i=0; i<size;++i){
            if (s[i] == 'S') s++;
            else if (s[i] == 'R') r++;
            else p++;
        }
        if ( r==p && p==s) cout<<s<<endl;
        else if ((r>p && r>=s) || r>=p && r>s) {
            for (int i=0;i<size;++i) cout<<'P';}
        cout<<endl;
        else if ( p > s )
    }
}
