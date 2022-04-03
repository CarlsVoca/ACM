#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1000005;

int a[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,m){
        int q;
        scanf("%d",&q);
        int pos=lower_bound(a+1,a+n+1,q)-a;
        if(a[pos]==q)printf("%d ",pos);
        else printf("-1 ");
    }
    return 0;
}