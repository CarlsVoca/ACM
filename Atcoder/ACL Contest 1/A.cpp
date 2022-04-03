#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int n;

struct Point{
    int x,y,id;
    bool operator < (const Point &b)const{
        return x<b.x;
    }
}p[maxn];

namespace Union_Find{
    int f[maxn],sz[maxn],MIN[maxn];
    void Init(){
        rep(i,1,n)f[i]=i,sz[i]=1,MIN[i]=p[i].y;
    }
    int Find(int x){
        return x==f[x]?x:f[x]=Find(f[x]);
    }
    void Union(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(fx==fy)return;
        f[fx]=fy;sz[fy]+=sz[fx];MIN[fy]=min(MIN[fx],MIN[fy]);
    }
}
using namespace Union_Find;

stack<int> sta;
int ans[maxn];

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
    sort(p+1,p+n+1);
    Init();
    rep(i,1,n){
        while(!sta.empty()&&MIN[Find(sta.top())]<p[i].y){
            int tmp=sta.top();sta.pop();
            Union(i,tmp);
        }
        sta.push(i);
    }
    rep(i,1,n)ans[p[i].id]=sz[Find(i)];
    rep(i,1,n)printf("%d\n",ans[i]);
    return 0;
}