#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

LL dp[20][10][10];

void Init(){
	for(int i=0;i<=9;i++)dp[1][i][i]=1;
	for(int i=2;i<=12;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++){
				if(k==j)dp[i][j][k]+=pow(10LL,i-1);
				for(int l=0;l<=9;l++){
					dp[i][j][k]+=dp[i-1][l][k];
				}
			}
	return;
}

LL sum(LL x,int tar){
	int d[20],len=0;
	LL ans=0;
	while(x){d[++len]=x%10;x/=10;}
	LL tmp[20];tmp[0]=0;
	for(int i=1;i<=len;i++)tmp[i]=d[i]*pow(10LL,i-1)+tmp[i-1];
	for(int i=len;i>=1;i--){
		for(int j=0+(i==len);j<d[i]+(i==1);j++){
			ans+=dp[i][j][tar];
//			printf("dp[%d][%d][%d]=%lld\n",i,j,tar,dp[i][j][tar]);
		}
		if(d[i]==tar&&i!=1)ans+=(tmp[i-1]+1);
	}
//	if(tar==1)printf("CCC:%lld\n",ans);
	for(int i=1;i<len;i++)
		for(int j=1;j<=9;j++)
			ans+=dp[i][j][tar];
	return ans;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	LL a,b;
	Init();
	while(scanf("%lld%lld",&a,&b)==2){
        if(a==0&&b==0)break;
        if(a>b)swap(a,b);
	    for(int i=0;i<=9;i++)printf("%lld ",sum(b,i)-sum(a-1,i));
        putchar('\n');
    }
    return 0;
}