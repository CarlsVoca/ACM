#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int cnt[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int res=n;
    rep(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        cnt[min(u,v)]++;
        if(cnt[min(u,v)]==1)res--;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int tp,u,v;
        scanf("%d",&tp);
        if(tp==1){
            scanf("%d%d",&u,&v);
            cnt[min(u,v)]++;
            if(cnt[min(u,v)]==1)res--;
        }
        else if(tp==2){
            scanf("%d%d",&u,&v);
            cnt[min(u,v)]--;
            if(cnt[min(u,v)]==0)res++;
        }
        else{
            printf("%d\n",res);
        }
    }
    return 0;
}