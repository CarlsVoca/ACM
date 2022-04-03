#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10005;

int f[maxn];

void Init(int n){
    rep(i,1,n)f[i]=i;
}

int Find(int x){
    return x==f[x]?x:f[x]=Find(f[x]);
}

struct Data{
    int p,d;
    bool operator < (const Data &b)const{
        return p==b.p?d>b.d:p>b.p;
    }
}d[maxn];

int main(){
    int n;
    while(scanf("%d",&n)==1){
        Init(10000);
        rep(i,1,n)scanf("%d%d",&d[i].p,&d[i].d);
        sort(d+1,d+n+1);
        int ans=0;
        rep(i,1,n){
            int l=Find(d[i].d);
            if(l==0)continue;
            else{
                // printf("debug:i=%d\n",i);
                ans+=d[i].p;
                f[l]=l-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}