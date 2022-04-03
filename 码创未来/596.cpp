#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=505;
const LL INF=1LL<<60;

LL dp[maxn][maxn];

int main(){
	memset(dp,0x3f,sizeof(dp));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%lld",&dp[i][j]);
        }
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",dp[i][j]);
        }
        putchar('\n');
    }
	return 0;
}