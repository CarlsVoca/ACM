#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<LL,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=200005;

LL w[maxn];
int d[maxn];
int n;
priority_queue<pii> pq;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        while(!pq.empty())pq.pop();
        scanf("%d",&n);
        LL ans=0;
        rep(i,1,n)d[i]=0;
        rep(i,1,n)scanf("%lld",&w[i]),ans+=w[i];
        rep(i,1,n-1){
            int u,v;
            scanf("%d%d",&u,&v);
            d[u]++;
            d[v]++;
        }
        rep(i,1,n){
            if(d[i]-1)pq.push(make_pair(w[i],d[i]-1));
        }
        printf("%lld",ans);
        rep(i,2,n-1){
            if(pq.empty()){
                printf(" %lld",ans);
                continue;
            }
            pii tmp=pq.top();pq.pop();
            ans+=tmp.first;
            if(tmp.second-1){
                tmp.second--;
                pq.push(tmp);
            }
            printf(" %lld",ans);
        }
        putchar('\n');
    }
    return 0;
}