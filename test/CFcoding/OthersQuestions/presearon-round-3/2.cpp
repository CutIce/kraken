#include<cstdio>
#include<iostream>

using namespace std;

int nowcnt,n,a[100010];
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int x=0;x<=30;x++)
	{
		nowcnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]&(1<<x))ans+=1ll*nowcnt*(1<<x),nowcnt++;
	}
	cout<<ans;
}
