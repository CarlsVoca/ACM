#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn],sum[maxn],b[maxn];

int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        rep(i,1,n){
            scanf("%d",&a[i]);
            if(a[i]>=m)b[i]=1;
            else b[i]=-1;
        }
        rep(i,1,n)sum[i]=sum[i-1]+b[i];
        if(sum[n]<=0){
            puts("-1");
            continue;
        }
        int tot=0,ans=0;
        rep(i,1,n){
            tot+=b[i];
            if(i==n)ans++;
            else if(tot>0){
                if(sum[n]-sum[i]>0){
                    ans++;
                    tot=0;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}