#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x7fffffff;
const int maxn=100005;

int pre[maxn],neg[maxn],a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n)pre[i]=pre[i-1]^a[i];
    per(i,n,1)neg[i]=neg[i+1]^a[i];
    int ans=INF;
    rep(i,1,n-1){
        int R=min(i+35,n),L=max(i-35,1);
        rep(j,i+1,R){
            per(k,i,L){
                if((pre[i]^pre[k-1])>(neg[i+1]^neg[j+1])){
                    // printf("debug:%d %d i=%d j=%d k=%d\n",pre[i]^pre[k-1],neg[i+1]^neg[j+1],i,j,k);
                    ans=min(ans,i-k+j-i-1);
                }
            }
        }
    }
    if(ans==INF)puts("-1");
    else printf("%d\n",ans);
    return 0;
}