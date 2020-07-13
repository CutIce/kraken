#include <iostream>
#include <vector>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    int n;
    while(cases--){
        cin >> n;
        vector<int> data(n);
        for (int i=0;i<n;++i){
            cin >> data[i];}
        for (int i = 0; i < n;++i){
            if (i%2 == 0) {
                if ( data[i] < 0 )
                    data[i] = -data[i];
            }
            else {
                if (data[i]>0)
                    data[i] = -data[i];
            }
            cout << data[i] << " ";
        }
        cout<<endl;
    }

}