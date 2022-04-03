#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

LL dpl[maxn][maxn],dpr[maxn][maxn];
int c[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&c[i]);
    rep(i,1,n){
        dpl[i][i]=dpr[i][i]=0;
        if(i&1){
            dpr[i][i]=c[i];
        }
        else dpl[i][i]=c[i];
    }
    rep(len,2,n){
        rep(i,1,n-len+1){
            int j=i+len-1;
            dpl[i][j]=dpl[i][j-1];
            dpr[i][j]=dpr[i][j-1];
            if(j&1){
                dpr[i][j]+=c[j];
            }
            else{
                if(c[j]<=dpr[i][j])dpr[i][j]-=c[j];
                else{
                    dpl[i][j]+=c[j]-dpr[i][j];
                    dpr[i][j]=0;
                }
            }
        }
    }
    LL ans=0;
    for(int i=1;i<n;i+=2){
        for(int j=i+1;j<=n;j+=2){
            if(j-i==1){
                ans+=min(c[i],c[j]);
            }
            else{
                // if(dpl[i+1][j-1]==0&&dpr[i+1][j-1]==0){ans+=min(c[i],c[j]);continue;}
                int tmp1=c[i],tmp2=c[j];
                if(tmp1<dpl[i+1][j-1])continue;
                if(tmp2<dpr[i+1][j-1])continue;
                tmp1-=dpl[i+1][j-1];
                tmp2-=dpr[i+1][j-1];
                ans+=min(tmp1,tmp2)+1;
            }
        }
    }
    // if(dpl[1][n]==0&&dpr[1][n]==0)ans++;
    printf("%lld\n",ans);
    return 0;
}