#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<ctime>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=40005;

int f[maxn],p[maxn][2];

void Init(int n){
    rep(i,1,n)f[i]=i,p[i][0]=p[i][1]=0;
}

int Find(int x){
    if(f[x]==x)return x;
    int tmp=f[x];
    f[x]=Find(f[x]);
    p[x][0]=p[x][0]+p[tmp][0];
    p[x][1]=p[x][1]+p[tmp][1];
    return f[x];
}

int a[maxn],b[maxn],l[maxn];
int ans[maxn];
char d[maxn];

struct Question{
    int a,b,c,id;
    bool operator < (const Question &b)const{
        return c<b.c;
    }
}q[maxn];

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        Init(n);
        rep(i,1,m)cin>>a[i]>>b[i]>>l[i]>>d[i];
        int k;
        scanf("%d",&k);
        rep(i,1,k)scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c),q[i].id=i;
        sort(q+1,q+k+1);
        int t=0;
        rep(i,1,k){
            while(t<q[i].c&&t<m){
                t++;
                if(d[t]=='E'){
                    int fx=Find(a[t]),fy=Find(b[t]);
                    if(fx==fy)continue;
                    else{
                        f[fx]=fy;
                        p[fx][0]=-p[a[t]][0]-l[t]+p[b[t]][0];
                        p[fx][1]=-p[a[t]][1]+p[b[t]][1];
                    }
                }
                else if(d[t]=='W'){
                    int fx=Find(a[t]),fy=Find(b[t]);
                    if(fx==fy)continue;
                    else{
                        f[fx]=fy;
                        p[fx][0]=-p[a[t]][0]+l[t]+p[b[t]][0];
                        p[fx][1]=-p[a[t]][1]+p[b[t]][1];
                    }
                }
                else if(d[t]=='N'){
                    int fx=Find(a[t]),fy=Find(b[t]);
                    if(fx==fy)continue;
                    else{
                        f[fx]=fy;
                        p[fx][1]=-p[a[t]][1]-l[t]+p[b[t]][1];
                        p[fx][0]=-p[a[t]][0]+p[b[t]][0];
                    }
                }
                else if(d[t]=='S'){
                    int fx=Find(a[t]),fy=Find(b[t]);
                    if(fx==fy)continue;
                    else{
                        f[fx]=fy;
                        p[fx][1]=-p[a[t]][1]+l[t]+p[b[t]][1];
                        p[fx][0]=-p[a[t]][0]+p[b[t]][0];
                    }
                }
            }
            if(Find(q[i].a)==Find(q[i].b))ans[q[i].id]=abs(p[q[i].a][0]-p[q[i].b][0])+abs(p[q[i].a][1]-p[q[i].b][1]);
            else ans[q[i].id]=-1;
        }
        rep(i,1,k)printf("%d\n",ans[i]);
        putchar('\n');
    }
    return 0;
}