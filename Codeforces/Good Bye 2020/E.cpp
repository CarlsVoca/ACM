#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=500005;
const int MOD=1e9+7;

LL a[maxn];
int cnt[66];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%lld",&a[i]);
            rep(j,0,59){
                if((1LL<<j)&a[i])cnt[j]++;
            }
        }
        LL ans=0;
        rep(i,1,n){
            LL res1=0,res2=0;
            rep(j,0,59){
                if((1LL<<j)&a[i]){
                    res1+=(1LL<<j)%MOD*cnt[j]%MOD;
                    res1%=MOD;
                }
            }
            rep(j,0,59){
                if((1LL<<j)&a[i])res2+=(1LL<<j)%MOD*n%MOD;
                else res2+=(1LL<<j)%MOD*cnt[j]%MOD;
                res2%=MOD;
            }
            // printf("debug:%lld %lld\n",res1,res2);
            ans+=res1*res2%MOD;
            ans%=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}