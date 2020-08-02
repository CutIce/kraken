#include<cstdio>
#include<algorithm>

using namespace std;

long long ans,l,r,mid,E,EM,M,MH,H;

inline int check(long long E,long long EM,long long M,long long MH,long long H)
{
	if(E+EM<mid||H+MH<mid)return 0;
	if(M+min(EM,EM-(mid-E))+min(MH,MH-(mid-H))<mid)return 0;
	return 1;
}

class ProblemSets{
public:
	long long maxSets(long long E,long long EM,long long M,long long MH,long long H)
	{
		l=1;r=E+EM+M+MH+H;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(E,EM,M,MH,H))ans=mid,l=mid+1;
			else r=mid-1;
		}
		return ans;
	}
}aa;

int main()
{
	scanf("%lld%lld%lld%lld%lld",&E,&EM,&M,&MH,&H);
	printf("%lld",aa.maxSets(E,EM,M,MH,H));
}
