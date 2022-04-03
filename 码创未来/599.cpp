#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=805;
const LL INF=1LL<<60;

LL dp[maxn][maxn];
int cnt[maxn];

int main(){
	memset(dp,0x3f,sizeof(dp));
	int p,n,m;
	scanf("%d%d%d",&p,&n,&m);
    for(int i=1;i<=p;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		int u,v;
        LL w;
		scanf("%d%d%lld",&u,&v,&w);
		dp[u][v]=dp[v][u]=min(dp[u][v],w);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	LL ans=INF;
	for(int i=1;i<=n;i++){
		LL res=0;
		for(int j=1;j<=n;j++){
			res+=dp[i][j]*cnt[j];
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}