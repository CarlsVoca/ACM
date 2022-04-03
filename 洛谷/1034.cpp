#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=55;
const int maxk=5;

struct Point{
    int x,y;
    bool operator == (const Point & p)const{
        return x==p.x&&y==p.y;
    }
}p[maxn];

int n,k;

struct Rectangle{
    Point a,b;
    bool operator == (const Rectangle & r)const{
        return a==r.a&&b==r.b;
    }
}rec[maxk],non;

int ans=INF;

bool inside(Point a,Rectangle b){
    return a.x>=b.a.x&&a.x<=b.b.x&&a.y>=b.a.y&&a.y<=b.b.y;
}

bool judge(Rectangle a,Rectangle b){
    return inside(a.a,b)||inside(a.b,b)||inside(Point{a.a.x,a.b.y},b)||inside(Point{a.b.x,a.a.y},b);
}

void dfs(int x){
    if(x==n+1){
        int res=0;
        rep(i,1,k){
            if(rec[i]==non)continue;
            res+=(rec[i].b.x-rec[i].a.x)*(rec[i].b.y-rec[i].a.y);
        }
        // if(res<=10){
        //     rep(i,1,k)printf("[%d,%d] [%d,%d]\n",rec[i].a.x,rec[i].a.y,rec[i].b.x,rec[i].b.y);
        //     printf("%d\n",res);
        // }
        ans=min(res,ans);
        return;
    }
    int res=0;
    rep(i,1,k){
        if(rec[i]==non)continue;
        res+=(rec[i].b.x-rec[i].a.x)*(rec[i].b.y-rec[i].a.y);
    }
    if(res>=ans)return;
    Rectangle pre[maxk];
    rep(i,1,k)pre[i]=rec[i];
    rep(i,1,k){
        if(rec[i]==non){
            rec[i].a=rec[i].b=p[x];
        }
        else{
            rec[i].a.x=min(rec[i].a.x,p[x].x);
            rec[i].a.y=min(rec[i].a.y,p[x].y);
            rec[i].b.x=max(rec[i].b.x,p[x].x);
            rec[i].b.y=max(rec[i].b.y,p[x].y);
        }
        bool flag=1;
        rep(j,1,k){
            if(i==j)continue;
            if(judge(rec[i],rec[j])){flag=0;break;}
        }
        if(flag)dfs(x+1);
        rec[i]=pre[i];
    }
}

int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
    non.a=Point{1,1};non.b=Point{0,0};
    rep(i,1,k){
        rec[i]=non;
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}