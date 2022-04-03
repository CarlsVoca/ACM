#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

double p[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,0,n-1)scanf("%lf",&p[i]);
        LL ans=0,pri=p[0];
        rep(i,1,n-1){
            if(p[i]/pri*100>k){
                LL tmp=pri;
                pri=ceil(100*p[i]/k);
                ans+=pri-tmp;
            }
            pri+=p[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}