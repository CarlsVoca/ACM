#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;
const int MOD=998244353;

int a[maxn],b[maxn],pos[maxn];
set<int> s;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        LL ans=1;
        scanf("%d%d",&n,&k);
        rep(i,1,n)scanf("%d",&a[i]),pos[a[i]]=i;
        rep(i,1,k)scanf("%d",&b[i]),s.insert(b[i]);
        rep(i,1,k){
            s.erase(b[i]);
            int mul=0;
            if(pos[b[i]]>1&&!s.count(a[pos[b[i]]-1]))mul++;
            if(pos[b[i]]<n&&!s.count(a[pos[b[i]]+1]))mul++;
            ans=(ans*mul)%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}