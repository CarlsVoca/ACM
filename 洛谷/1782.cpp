#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,LL> pil;

const int INF=0x3f3f3f3f;
const int maxn=1e4+5;

deque<pil> q;
LL dp[maxn];

int main(){
    int n,m,C;
    scanf("%d%d%d",&n,&m,&C);
    int v,w,l;
    rep(i,1,n){
        scanf("%lld%lld%lld",&v,&w,&l);
        for(int x=0;x<v;x++){
            while(!q.empty())q.pop_back();
            for(int j=x,k=1;j<=C;j+=v,k++){
                LL res=dp[j]-k*w;
                while(!q.empty()&&q.back().second<=res)q.pop_back();
                q.push_back(pil(k,res));
                dp[j]=q.front().second+k*w;
                while(!q.empty()&&q.front().first==k-l)q.pop_front();
            }
        }
    }
    for(int i=1;i<=m;i++){
        LL a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        for(int j=C;j>=0;j--){
            for(int k=0;k<=j;k++){
                dp[j]=max(dp[j],dp[j-k]+(a*k+b)*k+c);
            }
        }
    }
    printf("%lld\n",dp[C]);
    return 0;
}