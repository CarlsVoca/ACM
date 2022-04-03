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
const int maxn=2005;
const int maxm=1000005;

int f[maxn],p[maxn];

void Init(int n){
    rep(i,1,n)f[i]=i,p[i]=0;
}

int Find(int x){
    if(f[x]==x)return x;
    int tmp=f[x];
    f[x]=Find(tmp);
    p[x]=p[x]^p[tmp];
    return f[x];
}

int a[maxm],b[maxm];

int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        printf("Scenario #%d:\n",++cas);
        int n,m;
        scanf("%d%d",&n,&m);
        Init(n);
        rep(i,1,m)scanf("%d%d",&a[i],&b[i]);
        bool flag=0;
        rep(i,1,m){
            int fx=Find(a[i]),fy=Find(b[i]);
            if(fx!=fy){
                f[fx]=fy;
                p[fx]=p[a[i]]^p[b[i]]^1;
            }
            else if(p[a[i]]==p[b[i]]){flag=1;break;}
        }
        if(flag)puts("Suspicious bugs found!");
        else puts("No suspicious bugs found!");
        putchar('\n');
    }
    return 0;
}