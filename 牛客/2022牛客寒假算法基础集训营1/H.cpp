#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;

int a[maxn],b[maxn],c[maxn];
int sumb[maxn],sumc[maxn];
int tb=0,tc=0;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
    }
    rep(i,1,n){
        if(a[i]>=500)b[++tb]=a[i]-500;
        else c[++tc]=500-a[i];
    }
    sort(b+1,b+tb+1);
    sort(c+1,c+tc+1);
    rep(i,1,tb)sumb[i]=sumb[i-1]+b[i];
    rep(i,1,tc)sumc[i]=sumc[i-1]+c[i];
    LL ans=0;
    rep(i,1,tb){
        int pos=lower_bound(c+1,c+tc+1,b[i])-c;
        if(pos==tc+1){
            ans+=1LL*b[i]*tc-sumc[tc];
        }
        else{
            ans+=1LL*b[i]*(pos-1)-sumc[pos-1];
            ans+=sumc[tc]-sumc[pos-1]-1LL*b[i]*(tc-(pos-1));
        }
    }
    ans+=1LL*sumb[tb]*(tb-1);
    ans+=1LL*sumb[tb]*2;
    ans+=1LL*sumc[tc]*(tc-1);
    ans+=1LL*sumc[tc]*2;
    printf("%lld\n",ans);
    return 0;
}