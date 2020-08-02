#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int f1[N], f2[N];
map<pair<int, int>, int> ans;

int getf(int *f, int u) {
	if(u == f[u])return u;
	return f[u] = getf(f, f[u]);
}

void merge(int *f, int x, int y) {
	int u = getf(f, x), v = getf(f, y);
	if(u != v)f[u] = v;
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		f1[i] = f2[i] = i;
	}
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		merge(f1, x, y);
	}
	for(int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		merge(f2, x, y);
	}
	for(int i = 1; i <= n; i++) {
		ans[make_pair(getf(f1, i), getf(f2, i))]++;
	}
	for(int i = 1; i <= n; i++) {
		printf("%d", ans[make_pair(getf(f1, i), getf(f2, i))]);
		if(i == n)puts("");
		else putchar(' ');
	}
}
