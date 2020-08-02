#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N][11];
map<unsigned long long, int> cnt;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
			scanf("%d", &a[i][j]);
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		unsigned long long nowh = 0;
		for(int j = 2; j <= k; j++) {
			nowh = nowh * 233 + a[i][j] - a[i][1];
		}
		ans += cnt[-nowh];
		cnt[nowh]++;
	}
	printf("%lld\n", ans);
}
