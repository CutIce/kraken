#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; 
	scanf("%d", &n);
	int X1 = 100010, Y1 = 100010, X2 = -100010, Y2 = -100010;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 2; j++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			X1 = min(X1, x), Y1 = min(Y1, y);
			X2 = max(X2, x), Y2 = max(Y2, y);
		}
	}
	printf("%d\n", (Y2 - Y1) * (X2 - X1));
}
