#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5005;

struct Data{
    int w,h,id;
    bool operator < (const Data &d)const{
        return w<d.w;
    }
}d[maxn];

int dp[maxn],pre[maxn],anss[maxn],t=0;

int main(){
    int n,w,h;
    scanf("%d%d%d",&n,&w,&h);
    rep(i,1,n)scanf("%d%d",&d[i].w,&d[i].h),d[i].id=i;
    sort(d+1,d+n+1);
    int ans=0,anspos=0;
    rep(i,1,n){
        if(d[i].w<=w||d[i].h<=h)continue;
        rep(j,1,i-1){
            if(d[i].w>d[j].w&&d[i].h>d[j].h){
                if(dp[j]>dp[i])pre[i]=j,dp[i]=dp[j];
            }
        }
        dp[i]++;
        if(dp[i]>ans)ans=dp[i],anspos=i;
    }
    printf("%d\n",ans);
    for(int i=anspos;i;i=pre[i]){
        anss[++t]=d[i].id;
    }
    per(i,t,1)printf("%d ",anss[i]);
    return 0;
}