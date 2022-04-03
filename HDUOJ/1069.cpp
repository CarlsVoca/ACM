#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=35;

struct Cube{
    int a,b,c;
    bool operator < (const Cube &d)const{
        return a==d.a?b<d.b:a<d.a;
    }
}d[maxn*6];

int dp[maxn*6];

int main(){
    int n,cas=0;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        rep(i,1,n){
            scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
            d[i+n].a=d[i].a;d[i+n].b=d[i].c;d[i+n].c=d[i].b;
            d[i+2*n].a=d[i].b;d[i+2*n].b=d[i].a;d[i+2*n].c=d[i].c;
            d[i+3*n].a=d[i].b;d[i+3*n].b=d[i].c;d[i+3*n].c=d[i].a;
            d[i+4*n].a=d[i].c;d[i+4*n].b=d[i].a;d[i+4*n].c=d[i].b;
            d[i+5*n].a=d[i].c;d[i+5*n].b=d[i].b;d[i+5*n].c=d[i].a;
        }
        sort(d+1,d+6*n+1);
        int ans=0;
        rep(i,1,n*6){
            dp[i]=d[i].c;
            rep(j,1,i-1){
                if(d[i].a>d[j].a&&d[i].b>d[j].b)dp[i]=max(dp[i],dp[j]+d[i].c);
            }
            ans=max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++cas,ans);
    }
    return 0;
}