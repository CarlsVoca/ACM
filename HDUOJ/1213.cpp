#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

namespace Union_Find{
    int f[maxn];
    void init(int n){
        rep(i,1,n)f[i]=i;
    }
    int find(int x){
        return x==f[x]?x:f[x]=find(f[x]);
    }
    void Union(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy)return;
        else f[fx]=fy;
    }
}
using namespace Union_Find;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        init(n);
        int m;
        scanf("%d",&m);
        rep(i,1,m){
            int x,y;
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        rep(i,1,n)find(i);
        sort(f+1,f+n+1);
        int ans=0;
        rep(i,1,n)if(f[i]!=f[i-1])ans++;
        printf("%d\n",ans);
    }
    return 0;
}