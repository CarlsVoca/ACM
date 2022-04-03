#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=55;

int a[maxn],b[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int MINA=INF,MINB=INF;
        rep(i,1,n)scanf("%d",&a[i]),MINA=min(MINA,a[i]);
        rep(i,1,n)scanf("%d",&b[i]),MINB=min(MINB,b[i]);
        LL ans=0;
        rep(i,1,n){
            int da=a[i]-MINA,db=b[i]-MINB;
            ans+=min(da,db)+abs(da-db);
        }
        printf("%lld\n",ans);
    }
    return 0;
}