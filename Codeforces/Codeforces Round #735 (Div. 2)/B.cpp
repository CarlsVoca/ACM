#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n)scanf("%d",&a[i]);
        if(n<=1000){
            LL ans=-INF;
            rep(i,1,n)rep(j,i+1,n){
                ans=max(ans,1LL*i*j-1LL*k*(a[i]|a[j]));
            }
            printf("%lld\n",ans);
        }
        else{
            LL ans=-INF;
            rep(i,n-1000,n)rep(j,i+1,n){
                ans=max(ans,1LL*i*j-1LL*k*(a[i]|a[j]));
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}