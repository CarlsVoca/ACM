#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;
const int maxm=2005;

struct Edge{
    int u,v,w,nxt;
}e[maxm];
int nume=0;
int last[maxn];

void add_edge(int u,int v,int w){
    e[++nume]=Edge{u,v,w,last[u]};
    last[u]=nume;
}

int n,k,m;
int dp[maxn][maxn][maxn][2];

int main(){
    scanf("%d%d%d",&n,&k,&m);
    rep(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(v,u,w);
    }
    memset(dp,0x3f,sizeof(dp));
    rep(i,1,n){
        dp[i][i][1][0]=0;
        for(int j=last[i];j;j=e[j].nxt){
            int v=e[j].v;
            dp[min(i,v)][max(i,v)][2][v<i?0:1]=min(dp[min(i,v)][max(i,v)][2][v<i?0:1],dp[i][i][1][0]+e[j].w);
        }
    }
    int ans=INF;
    rep(len,2,n){
        rep(i,1,n-len+1){
            int j=i+len-1;
            rep(l,1,k){
                rep(o,0,1){
                    if(dp[i][j][l][o]==INF)continue;
                    if(l==k){
                        ans=min(ans,dp[i][j][l][o]);
                    }
                    // printf("debug:%d %d %d %d %d\n",i,j,l,o,dp[i][j][l][o]);
                    if(o==0){
                        for(int q=last[i];q;q=e[q].nxt){
                            int v=e[q].v;
                            if(v>=i&&v<=j)continue;
                            dp[min(i,v)][max(j,v)][l+1][v<i?0:1]=min(dp[min(i,v)][max(v,j)][l+1][v<i?0:1],dp[i][j][l][o]+e[q].w);
                        }
                    }
                    else{
                        for(int q=last[j];q;q=e[q].nxt){
                            int v=e[q].v;
                            if(v>=i&&v<=j)continue;
                            dp[min(i,v)][max(j,v)][l+1][v<i?0:1]=min(dp[min(i,v)][max(v,j)][l+1][v<i?0:1],dp[i][j][l][o]+e[q].w);
                        }
                    }
                }
            }
        }
    }
    if(k==1)ans=0;
    printf("%d\n",ans==INF?-1:ans);
    return 0;
}