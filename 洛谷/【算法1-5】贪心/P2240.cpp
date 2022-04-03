#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

struct Gold{
    int m,v;
    bool operator < (const Gold &b)const{
        return v*1.0/m>b.v*1.0/b.m;
    }
}g[maxn];

int main(){
    int n,T;
    scanf("%d%d",&n,&T);
    rep(i,1,n)scanf("%d%d",&g[i].m,&g[i].v);
    sort(g+1,g+n+1);
    double ans=0;
    rep(i,1,n){
        if(T>=g[i].m)T-=g[i].m,ans+=g[i].v;
        else{
            ans+=T*g[i].v*1.0/g[i].m;
            break;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}