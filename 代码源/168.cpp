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
    int n,m;
    scanf("%d%d",&n,&m);
    int v,w,l;
    rep(i,1,n){
        scanf("%d%d%d",&v,&w,&l);
        for(int x=0;x<v;x++){
            while(!q.empty())q.pop_back();
            for(int j=x,k=1;j<=m;j+=v,k++){
                int res=dp[j]-k*w;
                while(!q.empty()&&q.back().second<=res)q.pop_back();
                q.push_back(pil(k,res));
                dp[j]=q.front().second+k*w;
                while(!q.empty()&&q.front().first==k-l)q.pop_front();
            }
        }
    }
    printf("%lld\n",dp[m]);
    return 0;
}