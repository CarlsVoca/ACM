#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

LL d[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,2*n)scanf("%lld",&d[i]);
        sort(d+1,d+2*n+1);
        bool flag=1;
        LL res=0,pre=0;
        if(d[1]!=d[2])flag=0;
        for(int i=3;i<=2*n;i+=2){
            // printf("debug:%d %d\n",d[i]-d[i-2],i-1);
            if(d[i]!=d[i+1]||d[i]==d[i-2]){flag=0;break;}
            if((d[i]-d[i-2])%(i-1)==0){
                // printf("Debug:%lld\n",(d[i]-d[i-2])/(i-1));
                pre+=((d[i]-d[i-2])/(i-1));
                res+=pre;
                continue;
            }
            else {flag=0;break;}
        }
        // printf("debug:%lld %lld %d\n",d[1],res,2*n);
        if(n==1&&d[1]%2!=0)flag=0;
        if(n>1&&(d[1]<=2*res||(d[1]-2*res)%(2*n)!=0))flag=0;
        // double x=(d[1]-2*res)/(2.0*n);
        // printf("x=%lf\n",x);
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}