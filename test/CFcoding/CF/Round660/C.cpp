#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>
#include <string.h>
#include <tuple>
#include <set>
#include <vector>
#include <map>

using namespace std;

struct node{
    int people;
    int h;
    vector<int> next;
};
node tree[10010];

int main(){
    int cases;cin>>cases;
    while (cases--){
        int n;cin>>n;
        for (int i=1;i<=n;++i)
            cin>>tree[i].people;
        for (int i=1;i<=n;++i)
            cin>>tree[i].h;
        for (int i=0;i<n-1;++i){
            int city,tmp;
            cin>>city>>tmp;
            tree[city].next.push_back(tmp);
        }

    }

}