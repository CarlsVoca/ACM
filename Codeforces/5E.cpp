#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;

int h[maxn],a[maxn],l[maxn],r[maxn],cnt[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int pos=1;
    LL cntmax=0;
    rep(i,1,n){
        scanf("%d",&h[i]);
        if(h[i]==h[pos])cntmax++;
        if(h[i]>h[pos])pos=i,cntmax=1;
    }
    rep(i,1,n+1)a[i]=h[(pos+i-2)%n+1];
    rep(i,2,n){
        l[i]=i-1;
        if(a[i]==a[1])continue;
        while(a[l[i]]<=a[i])l[i]=l[l[i]];
    }
    per(i,n,2){
        r[i]=i+1;
        if(a[i]==a[1])continue;
        while(a[r[i]]<a[i])r[i]=r[r[i]];
        if(a[r[i]]==a[i]){
            cnt[i]=cnt[r[i]]+1;
            r[i]=r[r[i]];
        }
    }
    LL ans=0;
    rep(i,2,n){
        if(a[i]==a[1])continue;
        ans+=cnt[i];
        ans+=2;
        if(l[i]==1&&r[i]==n+1)ans--;
    }
    printf("%lld\n",ans+cntmax*(cntmax-1)/2);
}