#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int a[N];
long long f[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	f[1] = f[0] = 0;
	long long ans = -2e9;
	for(int i = 2; i <= n; i++) {
		f[i] = f[i - 2] + a[i] + a[i - 1];
		ans = max(ans, f[i]);
		f[i] = max(f[i], 0ll);
	}
	printf("%lld\n", ans);
}
