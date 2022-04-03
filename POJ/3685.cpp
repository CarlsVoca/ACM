#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define rep(i,a,b) for(LL i=(a);i<=(b);i++)
#define per(i,a,b) for(LL i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=1LL<<62;

LL n,m;

LL f(LL i,LL j){
    if(i==0)return -INF;
    return i*i+100000*i+j*j-100000*j+i*j;
}

bool check(LL ans){
    LL cnt=0;
    rep(j,1,n){
        LL l=0,r=n;
        while(l<r){
            LL mid=(l+r>>1)+1;
            if(f(mid,j)>ans)r=mid-1;
            else l=mid;
        }
        cnt+=l;
    }
    return cnt>=m;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        LL ansl=-INF,ansr=INF;
        while(ansl<ansr){
            LL mid=ansl+ansr>>1;
            if(!check(mid))ansl=mid+1;
            else ansr=mid;
            // printf("%lld\n",mid);
        }
        printf("%lld\n",ansl);
    }
    return 0;
}