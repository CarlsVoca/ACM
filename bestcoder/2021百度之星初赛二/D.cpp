#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int MOD=998244353;
const int maxn=100005;
const LL INF=(1LL<<60);

int a[maxn];
LL sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        LL m;
        scanf("%d%lld",&n,&m);
        LL MAX=-INF;
        rep(i,1,n){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
            MAX=max(MAX,sum[i]);
        }
        bool flag=0;
        LL x1=0,ans=0,x2=0;
        rep(i,1,n){
            x1+=a[i];
            if(x1<0)x1=0;
            if(x1>=m){
                flag=1;
                ans=1;
                break;
            }
        }
        if(flag){
            printf("%lld\n",ans);
            continue;
        }
        x2=x1;
        rep(i,1,n){
            x2+=a[i];
            if(x2<0)x2=0;
            if(x2>=m){
                flag=1;
                ans=2;
                break;
            }
        }
        if(flag){
            printf("%lld\n",ans);
            continue;
        }
        if(x2==x1){
            puts("-1");
            continue;
        }
        LL del=x2-x1;
        // printf("debug::x2=%lld del=%lld\n",x2,del);
        m-=MAX;
        // printf("debug:%lld\n",m);
        printf("%lld\n",(LL)ceil((double)(m-x2)/del)+3);
    }
    return 0;
}