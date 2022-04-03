#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10005;

int n,a[maxn];

namespace ST{
    int st[maxn][20];
    void Init(){
        rep(i,1,n)st[i][0]=a[i];
        for(int j=1;(1<<j)<=n;j++)
            for(int i=1;i+(1<<j)-1<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
            }
    }
    int query_min(int l,int r){
        int k=log2(r-l+1);
        return min(st[l][k],st[r-(1<<k)+1][k]);
    }
}
using namespace ST;

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    Init();
    LL ans=0;
    rep(i,1,n)
        rep(j,i,n){
            ans=max(ans,(j-i+1)*1LL*query_min(i,j));
        }
    printf("%lld\n",ans);
    return 0;
}