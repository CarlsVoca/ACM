#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=1LL<<58;
const int maxn=150005;

struct Data{
    int v,id;
    LL res;
    set<int> s;
    bool operator < (const Data& d)const{
        return res<d.res;
    }
}a[maxn],b[maxn],c[maxn],d[maxn];

int main(){
    int n1,n2,n3,n4;
    scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
    rep(i,1,n1)scanf("%d",&a[i].v),a[i].id=i;
    rep(i,1,n2)scanf("%d",&b[i].v),b[i].id=i,b[i].res=INF;
    rep(i,1,n3)scanf("%d",&c[i].v),c[i].id=i,c[i].res=INF;
    rep(i,1,n4)scanf("%d",&d[i].v),d[i].id=i,d[i].res=INF;
    int m1,m2,m3;
    rep(i,1,n1)a[i].res=a[i].v;
    scanf("%d",&m1);
    sort(a+1,a+n1+1);
    rep(i,1,m1){
        int x,y;
        scanf("%d%d",&x,&y);
        b[y].s.insert(x);
    }
    rep(i,1,n2){
        rep(j,1,n1){
            if(b[i].s.count(a[j].id))continue;
            else {b[i].res=a[j].res+b[i].v;break;}
        }
    }
    scanf("%d",&m2);
    sort(b+1,b+n2+1);
    rep(i,1,m2){
        int x,y;
        scanf("%d%d",&x,&y);
        c[y].s.insert(x);
    }
    rep(i,1,n3){
        rep(j,1,n2){
            if(c[i].s.count(b[j].id))continue;
            else {c[i].res=b[j].res+c[i].v;break;}
        }
    }
    scanf("%d",&m3);
    sort(c+1,c+n3+1);
    rep(i,1,m3){
        int x,y;
        scanf("%d%d",&x,&y);
        d[y].s.insert(x);
    }
    rep(i,1,n4){
        rep(j,1,n3){
            if(d[i].s.count(c[j].id))continue;
            else {d[i].res=c[j].res+d[i].v;break;}
        }
    }
    sort(d+1,d+n4+1);
    if(d[1].res>=INF)puts("-1");
    else printf("%lld\n",d[1].res);
    return 0;
}