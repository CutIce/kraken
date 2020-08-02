#include<cstdio>
#include<vector>

#define N 500050

using namespace std;

vector<int>g[4*N];
int flag[4*N],vis[4*N];
int dis[N],bo[N],q[N];
int l,v,h,n,m,p,a[2*N],b[2*N],c[2*N],d[2*N];

void add(int k,int l,int r,int ll,int rr,int o)
{
	if(ll<=l&&r<=rr)
	{
		g[k].push_back(o);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)add(k<<1,l,mid,ll,rr,o);
	if(mid<rr)add(k<<1|1,mid+1,r,ll,rr,o);
}

void dfs(int k,int ll,int rr)
{
	if(flag[k])return;
	if(ll==rr)
	{
		flag[k]=1;
		q[++l]=ll;
		dis[ll]=dis[v]+1;
		return;
	}
	dfs(k<<1,ll,(ll+rr)>>1);
	dfs(k<<1|1,((ll+rr)>>1)+1,rr);
	flag[k]=flag[k<<1]&flag[k<<1|1];
}

void upd(int k,int l,int r,int ll,int rr)
{
	if(flag[k])return;
	if(ll<=l&&r<=rr)
	{
		dfs(k,l,r);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)upd(k<<1,l,mid,ll,rr);
	if(mid<rr)upd(k<<1|1,mid+1,r,ll,rr);
}

void up(int k,int l,int r,int ll)
{
	if(!vis[k])
	{
		vis[k]=1;
		for(int i=0;i<(int)g[k].size();i++)
			if(!bo[g[k][i]])
			{
				bo[g[k][i]]=1;
				upd(1,1,n,c[g[k][i]],d[g[k][i]]);
			}
	}
	if(l==r)return;
	int mid=(l+r)>>1;
	if(mid>=ll)up(k<<1,l,mid,ll);
	else up(k<<1|1,mid+1,r,ll);
}

inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;i++)
	{
		read(a[i*2-1]),read(b[i*2-1]),read(c[i*2-1]),read(d[i*2-1]);
		a[i*2]=c[i*2-1];b[i*2]=d[i*2-1],c[i*2]=a[i*2-1];d[i*2]=b[i*2-1];
		add(1,1,n,a[i*2-1],b[i*2-1],i*2-1);
		add(1,1,n,a[i*2],b[i*2],i*2);
	}
	l=1;
	v=0;
	dis[v]=-1;
	q[1]=p;
	upd(1,1,n,p,p);
	while(h<l)
	{
		v=q[++h];
		up(1,1,n,v);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",dis[i]);
}
