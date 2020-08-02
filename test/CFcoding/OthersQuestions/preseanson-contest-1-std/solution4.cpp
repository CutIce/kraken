#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct Edge{
	int x, y, v, next;
}edge[M << 1];

int n, m, k, tot;
int son[N], vis[N], q[N];

inline void add(int x, int y, int v) {
	edge[++tot].x = x; edge[tot].y = y; edge[tot].v = v; edge[tot].next = son[x]; son[x] = tot;
}

inline long long get(int k) {
	long long nowans = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) {
		if(vis[i])continue;
		int h = 0, l = 0;
		q[++l] = i;
		vis[i] = 1;
		while(h < l) {
			int x = q[++h];
			for(int i = son[x]; i; i = edge[i].next) {
				int y = edge[i].y;
				if(edge[i].v > k)continue;
				if(vis[y])continue;
				q[++l] = y;
				vis[y] = 1;
			}
		}
		nowans += 1ll * l * (l - 1);
	}
	return nowans / 2;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		add(x, y, v);
		add(y, x, v);
	}
	printf("%lld\n", get(k) - get(k - 1));
}
