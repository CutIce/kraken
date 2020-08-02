#include<cstdio>

#define mo 1000000007

using namespace std;

struct Edge{
	int x,y,next;
}edge[2001*2001];

int n,m,k,l,h,v,ans,tot;
int q[2020],son[2020],flag[2020];

inline void add(int x,int y)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

void bfs(int st)
{
	h=l=0;
	q[++l]=st;
	while(h<l)
	{
		v=q[++h];
		for(int i=son[v];i;i=edge[i].next)
			if(!flag[edge[i].y])flag[edge[i].y]=1,q[++l]=edge[i].y;
	}
	ans=1ll*ans*m%mo;
}

int main()
{
	ans=1;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n-k+1;i++)
        for(int j=0;j<k;j++)
            add(i+j,i+k-j-1);
    for(int i=1;i<=n;i++)
        if(!flag[i])bfs(i);
    printf("%d",ans);
}
