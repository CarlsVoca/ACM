#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<string,string> pss;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

string a[maxn],b[maxn];
map<pss,int> cnt;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)cin>>a[i]>>b[i];
    rep(i,1,n)cnt[pss(a[i].substr(0,2),b[i])]++;
    LL ans=0;
    rep(i,1,n){
        if(a[i].substr(0,2)==b[i])continue;
        else{
            ans+=cnt[pss(b[i],a[i].substr(0,2))];
        }
    }
    printf("%lld\n",ans/2);
    return 0;
}