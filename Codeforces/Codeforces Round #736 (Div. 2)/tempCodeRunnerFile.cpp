#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int n;

LL st[maxn][20];
void init(){
	for(int j=1;(1<<j)<=n-1;j++)
		for(int i=1;i+(1<<j)-1<=n-1;i++){
			st[i][j]=__gcd(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
}
LL query_gcd(int l,int r){
	int k=log2(r-l+1);
	return __gcd(st[l][k],st[r-(1<<k)+1][k]);
}

LL a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n)scanf("%lld",&a[i]);
        rep(i,1,n-1){
            st[i][0]=abs(a[i+1]-a[i]);
        }
        init();
        int l=1,ans=0;
        rep(r,1,n-1){
            while(l<=r&&query_gcd(l,r)==1)l++;
            ans=max(ans,r-l+1);
            // printf("debug:%d %d\n",l,r);
        }
        printf("%d\n",ans+1);
    }
    return 0;
}