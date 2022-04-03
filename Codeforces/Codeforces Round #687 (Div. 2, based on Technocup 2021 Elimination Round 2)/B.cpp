#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int c[maxn],n,k;

int check(int ans){
    int res=0;
    rep(i,1,n){
        if(c[i]==ans)continue;
        else{
            res++;
            i+=k-1;
        }
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        rep(i,1,n)scanf("%d",&c[i]);
        int ans=INF;
        rep(i,1,200){
            ans=min(ans,check(i));
        }
        printf("%d\n",ans);
    }
    return 0;
}