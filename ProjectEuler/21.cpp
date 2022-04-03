#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1000005;

int d[maxn];
bool ami[maxn];

void cul_d(int x){
    rep(i,1,sqrt(x)){
        if(x%i==0){
            if(i*i!=x){
                d[x]+=i;
                d[x]+=x/i;
            }
            else d[x]+=i;
        }
    }
    d[x]-=x;
}

int main(){
    LL ans=0;
    rep(i,1,10000)cul_d(i);
    // printf("%d %d\n",d[220],d[d[220]]);
    rep(i,1,10000){
        if(d[i]<=10000&&i==d[d[i]]&&i!=d[i])ans+=i;
    }
    printf("%lld\n",ans);
    return 0;
}