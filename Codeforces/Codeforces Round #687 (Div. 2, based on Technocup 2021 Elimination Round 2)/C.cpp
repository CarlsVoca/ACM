#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x7fffffff;
const int maxn=100005;

char s[maxn];
int cnt[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,p,k;
        scanf("%d%d%d",&n,&p,&k);
        scanf("%s",s+1);
        int x,y;
        scanf("%d%d",&x,&y);
        per(i,n,p){
            if(i+k<=n)cnt[i]=cnt[i+k];
            else cnt[i]=0;
            if(s[i]=='0')cnt[i]++;
        }
        int ans=INF;
        rep(i,p,n){
            ans=min(ans,(i-p)*y+cnt[i]*x);
        }
        printf("%d\n",ans);
    }
    return 0;
}