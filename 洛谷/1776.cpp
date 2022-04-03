#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<LL,int> pli;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

LL dp[2][maxn];
int v[maxn],w[maxn],m[maxn];
pli q[maxn];
int head,tail;
LL ans=0;

int main(){
    int n,W;
    scanf("%d%d",&n,&W);
    rep(i,1,n)scanf("%d%d%d",&v[i],&w[i],&m[i]);
    rep(i,1,n){
        rep(base,0,w[i]-1){
            head=1,tail=0;
            LL pls=0;
            for(int j=0;j*w[i]+base<=W;j++){
                dp[i&1][j*w[i]+base]=dp[(i-1)&1][j*w[i]+base];
                while(head<=tail&&j-q[head].second>m[i])head++;
                if(head<=tail)dp[i&1][j*w[i]+base]=max(q[head].first+pls,dp[i&1][j*w[i]+base]);
                while(head<=tail&&q[tail].first+pls<=dp[(i-1)&1][j*w[i]+base])tail--;
                q[++tail]=pli(dp[(i-1)&1][j*w[i]+base]-pls,j);
                pls+=v[i];
                ans=max(ans,dp[i&1][j*w[i]+base]);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}