#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

struct Edge{
    int u,v,w,nxt;
}e[maxe];

int nume=0,last[maxn];

inline void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        
    }
    return 0;
}