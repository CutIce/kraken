#include<cstdio>
 
using namespace std;
 
int b[1000010];
 
int main()
{
	int n; 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		b[i] = b[i - 1] ^ i;
	int ans = 0;		
	for(int i = 2; i <= n; i++)
	{
		int o = n / i, now = 0;
		if(o % 2)now = b[i - 1];
		now ^= b[n % i];
		ans ^= now;
	}
	printf("%d", ans);
}
