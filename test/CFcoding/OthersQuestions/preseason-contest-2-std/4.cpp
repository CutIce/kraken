#include<queue>
#include<cstdio>
#include<iostream>

using namespace std;

priority_queue<long long>q;

int n,m,k,p,o;
long long hang[1010],lie[1010],X[100010],Y[100010],ans,now;

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d", &o),hang[i]+=o,lie[j]+=o;
	for(int i=1;i<=n;i++)
		q.push(hang[i]);
	for(int i=1;i<=k;i++)
	{
		now=q.top();
		X[i]=X[i-1]+now;
		q.pop();
		q.push(now-1ll*p*m);
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=m;i++)
		q.push(lie[i]);
	for(int i=1;i<=k;i++)
	{
		now=q.top();
		Y[i]=Y[i-1]+now;
		q.pop();
		q.push(now-1ll*p*n);
	}
	ans=-1000000000000000ll;
	for(int i=0;i<=k;i++)
		ans=max(ans,X[i]+Y[k-i]-1ll*p*i*(k-i));
	cout<<ans;
}
