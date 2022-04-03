#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=20;

int a[maxn][maxn],dp[maxn][maxn];

int main(){
	int n=15;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			scanf("%d",&a[i][j]);
		}
	for(int i=n;i>=1;i--)
		for(int j=i;j>=1;j--){
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
		}
	printf("%d\n",dp[1][1]);
	return 0;
}
