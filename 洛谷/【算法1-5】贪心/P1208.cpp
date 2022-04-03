#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2000005;

struct Milk{
    int p,a;
    bool operator < (const Milk &b)const{
        return p<b.p;
    }
}m[maxn];

int main(){
    int n,T;
    scanf("%d%d",&T,&n);
    rep(i,1,n)scanf("%d%d",&m[i].p,&m[i].a);
    sort(m+1,m+n+1);
    LL ans=0;
    rep(i,1,n){
        if(T>=m[i].a)T-=m[i].a,ans+=m[i].p*m[i].a;
        else{
            ans+=T*m[i].p;
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}