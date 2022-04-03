#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

struct Data{
    LL s,a;
}d[maxn];

LL a_min[maxn],dis_max[maxn],a_sum[maxn],neg[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%lld",&d[i].s);
    rep(i,1,n)scanf("%lld",&d[i].a);
    sort(d+1,d+n+1,[](Data a,Data b){
        return a.a>b.a;
    });
    a_min[0]=INF;dis_max[0]=0;a_sum[0]=0;
    rep(i,1,n){
        a_min[i]=min(a_min[i-1],d[i].a);
        dis_max[i]=max(dis_max[i-1],d[i].s);
        a_sum[i]=a_sum[i-1]+d[i].a;
    }
    neg[n+1]=0;
    per(i,n,1){
        neg[i]=max(neg[i+1],2*d[i].s+d[i].a);
    }
    rep(i,1,n){
        printf("%lld\n",max(a_sum[i]+dis_max[i]*2,a_sum[i]-a_min[i]+neg[i+1]));
    }
    return 0;
}