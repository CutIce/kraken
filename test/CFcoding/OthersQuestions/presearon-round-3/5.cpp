#include<cstdio>
#include<cstring>

#define mo 1000000009

using namespace std;

int ans,n,t,f[100010][2][2],a[100010];

int Pow(int x,int m)
{
	int nowans=1;
	while(m)
	{
		if(m&1)nowans=1ll*nowans*x%mo;
		x=1ll*x*x%mo;
		m>>=1;
	}
	return nowans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=1;
	for(int x=29;~x;x--)
	{
		t=0;
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		for(int i=1;i<=n;i++)
			if(a[i]&(1<<x))
			{
				t^=1;
				a[i]-=1<<x;
				for(int l=0;l<2;l++)
					for(int k=0;k<2;k++)
						(f[i][l][1]+=1ll*f[i-1][l][k]*(1<<x)%mo)%=mo,
						(f[i][l^1][k]+=1ll*f[i-1][l][k]*(a[i]+1)%mo)%=mo;
			}
			else
			{
				for(int l=0;l<2;l++)
					for(int k=0;k<2;k++)
						(f[i][l][k]+=1ll*f[i-1][l][k]*(a[i]+1)%mo)%=mo;
			}
		(ans+=1ll*f[n][t][1]*Pow(1<<x,mo-2)%mo)%=mo;
	}
	printf("%d",ans);
}
