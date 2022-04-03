#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int n;

namespace Union_Find{
    int f[maxn],Rank[maxn];
    void Pre(){
        memset(Rank,0,sizeof(Rank));
        for(int i=1;i<=n;i++)f[i]=i;
    }
    int Find(int x){
        return f[x]==x?x:f[x]=Find(f[x]);
    }
    void Union(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(fx!=fy){
            if(Rank[fx]>Rank[fy])f[fy]=fx;
            else{
                f[fx]=fy;
                if(Rank[fx]==Rank[fy])Rank[fy]++;
            }
        }
    }
}
using namespace Union_Find;

int e[maxn];

int main(){
    scanf("%d",&n);
    Pre();
    int q;
    scanf("%d",&q);
    while(q--){
        char opt;
        int p,q;
        cin>>opt>>p>>q;
        if(opt=='F')Union(p,q);
        else{
            if(e[q])Union(e[q],p);
            if(e[p])Union(q,e[p]);
            e[q]=p;
            e[p]=q;
        }
    }
    sort(f+1,f+n+1);
    int m=unique(f+1,f+n+1)-f-1;
    printf("%d\n",m);
    return 0;
}