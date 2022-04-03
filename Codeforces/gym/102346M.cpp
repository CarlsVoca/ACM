#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int p[maxn];
int n,c,t,MAX=0;

bool check(LL x){
    if(MAX>x*t)return 0;
    int cnt=1;
    LL res=0,pos=1;
    while(pos<=n){
        if(res+p[pos]<=x*t)res+=p[pos];
        else{
            res=p[pos];
            cnt++;
        }
        pos++;
    }
    if(cnt>c)return 0;
    else return 1;
}

int main(){
    scanf("%d%d%d",&n,&c,&t);
    rep(i,1,n){
        scanf("%d",&p[i]);
        MAX=max(MAX,p[i]);
    }
    // sort(a+1,a+n+1);
    LL r=INF,l=0;
    while(l<r){
        LL mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}