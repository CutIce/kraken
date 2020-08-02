#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,now,Cnt,l,cnt[2000020],flag[2000020],nowcnt[2000020],Min[2000020],q[110];

class MissingLCM{
public:
	int getMin(int n)
	{
		memset(Min,0x3f,sizeof(Min));
		for(int i=2;i<=2*n;i++)
			if(!flag[i])
				for(int j=i;j<=2*n;j+=i)flag[j]=1,Min[j]=min(Min[j],i);
		memset(flag,0,sizeof(flag));
		for(int i=2;i<=n;i++)
		{
			now=i;
			l=0;
			while(now!=1)
			{
				nowcnt[Min[now]]++;
				if(!flag[Min[now]])q[++l]=Min[now],flag[Min[now]] = 1 ;
				now/=Min[now];
			}
			for(int j=1;j<=l;j++)
				cnt[q[j]]=max(cnt[q[j]],nowcnt[q[j]]),nowcnt[q[j]]=0,flag[q[j]]=0;
		}
		for(int i=2;i<=n;i++)if(cnt[i])Cnt++;
		for(int i=n+1;i<=2*n;i++)
		{
			now=i;
			l=0;
			while(now!=1)
			{
				nowcnt[Min[now]]++;
				if(!flag[Min[now]])q[++l]=Min[now],flag[Min[now]]=1;
				now/=Min[now];
			}
			for(int j=1;j<=l;j++)
			{
				if(nowcnt[q[j]]>=cnt[q[j]]&&cnt[q[j]])Cnt--,cnt[q[j]]=0;
				nowcnt[q[j]]=0;flag[q[j]]=0;
			}
			if(!Cnt)return i;
		}
		return 2*n;
	}
}aa;

int main()
{
	scanf("%d",&n);
	printf("%d",aa.getMin(n));
}

