#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,d,shu[5];
const long long mod=998244353;
long long ans,dp[5][1010],C[1010][1010];
int main()
{
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	int mn=min(a,b);
	mn=min(mn,c);
	mn=min(mn,d);
	mn=min(mn,n/4);
	for(int i=0;i<=mn;++i)
	{
		long long opt=1;
		if(i&1)
		opt=-1;
		memset(dp,0,sizeof(dp));
		shu[1]=a-i;
		shu[2]=b-i;
		shu[3]=c-i;
		shu[4]=d-i;
		for(int j=0;j<=shu[1];++j)
		dp[1][j]=C[n-4*i][j];
		for(int j=2;j<=4;++j)
		{
			for(int k=0;k<=n;++k)
			{
				for(int l=max(0,k-shu[j]);l<=k&&n-4*i-l>=0;++l)
				dp[j][k]=(dp[j][k]+dp[j-1][l]*C[n-4*i-l][k-l]%mod)%mod;
			}
		}
		ans=(ans+opt*dp[4][n-4*i]*C[n-3*i][i]%mod+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}