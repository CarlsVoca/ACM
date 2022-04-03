#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=25;

int dp[1<<maxn];
int pre[1<<maxn];
int dis[maxn][maxn];

struct Point{
    int x,y;
}p[maxn];

int Dis(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(){
    scanf("%d%d",&p[0].x,&p[0].y);
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
    rep(i,0,n)rep(j,i+1,n)dis[i][j]=dis[j][i]=Dis(p[i],p[j]);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    rep(i,1,(1<<n)-1){
        rep(j,1,n){
            if((1<<j-1)&i){
                LL tmp=dp[i-(1<<j-1)]+2*dis[0][j];
                if(dp[i]>tmp){
                    dp[i]=tmp;
                    pre[i]=i-(1<<j-1);
                }
            }
            else continue;
            rep(k,j+1,n){
                if(((1<<j-1)&i)&&((1<<k-1)&i)){
                    LL tmp=dp[i-(1<<j-1)-(1<<k-1)]+dis[0][j]+dis[j][k]+dis[k][0];
                    if(dp[i]>tmp){
                        dp[i]=tmp;
                        pre[i]=i-(1<<j-1)-(1<<k-1);
                    }
                }
            }
            break;
        }
    }
    printf("%lld\n",dp[(1<<n)-1]);
    int p=(1<<n)-1;
    while(p){
        int del=p^pre[p];
        if(p==(1<<n)-1)printf("0 ");
        rep(i,1,n){
            if((1<<i-1)&del)printf("%d ",i);
        }
        printf("0 ");
        p=pre[p];
    }
    return 0;
}