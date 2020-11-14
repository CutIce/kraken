#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases;
    int n;
    int i=0;
    cin>>cases;
    while (i<cases){
        cin>>n;
        int nege=0,posi=0;
        int flag=0,now,tmp;  // -1<0   1>0
        vector<int> data(n);
        vector<int> diff(n-1);
        int j;  cin>>now; data.push_back(now);
        for (j=1;j<n;++j){
            data.push_back(now);
            tmp=now-data[j-1];
            if (tmp>0) posi++;
            else if (tmp<0) nege++;
            diff.push_back(tmp);
        }
        ++i;
    }

    return 0;

}