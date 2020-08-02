#include <bits/stdc++.h>

using namespace std;

const int mo = 1e9 + 7;

int power(int x, int m) {
	int nowans = 1;
	while(m) {
		if(m & 1)nowans = 1ll * nowans * x % mo;
		x = 1ll * x * x % mo;
		m >>= 1;
	}
	return nowans;
}

int main() {
	int n;
	scanf("%d", &n);
	int ans = 1ll * n * power(2, n - 1) % mo;
	printf("%d\n", ans);
}
