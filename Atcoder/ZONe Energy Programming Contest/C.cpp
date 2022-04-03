#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=3005;

int n;
int a[maxn],b[maxn],c[maxn],d[maxn],e[maxn];
bool dp[maxn][4][1<<6];

bool check(int x){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    rep(i,1,n){
        int t=0;
        if(a[i]>=x)t|=1;
        if(b[i]>=x)t|=1<<1;
        if(c[i]>=x)t|=1<<2;
        if(d[i]>=x)t|=1<<3;
        if(e[i]>=x)t|=1<<4;
        rep(j,0,3){
            rep(k,0,(1<<5)-1){
                dp[i][j][k]=dp[i-1][j][k];
            }
        }
        rep(j,0,2){
            rep(k,0,(1<<5)-1){
                if(dp[i-1][j][k]){
                    dp[i][j+1][k|t]=1;
                }
            }
        }
    }
    return dp[n][3][(1<<5)-1];
}

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&e[i]);
    int l=1,r=1e9;
    while(r>l){
        int mid=(l+r>>1)+1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}