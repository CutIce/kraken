//
// Created by hsh on 2020/7/17.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;cin >> n;
        vector<int> a(n);
        deque<int> res;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0, j = n - 1; i < n, j >= 0, i <= j;) {
            if (res.empty()) {
                if (a[i] < a[j]) res.push_back(i++);
                else res.push_back(j--);
                continue;}
            if (a[i] < a[j]) {
                if (!res.empty() && a[i] < a[res.back()]) {
                    j = n - 1;
                    res.resize(0);
                }
                else res.push_back(i++);
                }
            else {
                if (!res.empty() && a[j] < a[res.back()]) {
                    j = n - 1;i++;
                    res.resize(0);}
                else res.push_back(j--);
            }
        }
        //sort(res.begin(), res.end());
        cout << n-res.size() << endl;
    }
    return 0;
}
