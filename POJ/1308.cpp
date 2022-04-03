#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<ctime>
#include<map>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

map<int,bool> vis;
map<int,int> f;

int Find(int x){
    return f[x]==x?x:f[x]=Find(f[x]);
}

int main(){
    int u,v,cas=0;
    while(scanf("%d%d",&u,&v)==2){
        if(u<0&&v<0)break;
        if(u==0&&v==0){printf("Case %d is a tree.\n",++cas);continue;}
        f.clear();vis.clear();
        bool flag=1;
        int tot=0,nume=1;
        if(!vis[u])vis[u]=1,f[u]=u,tot++;
        if(!vis[v])vis[v]=1,f[v]=v,tot++;
        f[v]=u;
        while(scanf("%d%d",&u,&v)==2){
            if(u==0&&v==0)break;
            nume++;
            if(!vis[u])vis[u]=1,f[u]=u,tot++;
            if(!vis[v])vis[v]=1,f[v]=v,tot++;
            int fu=Find(u),fv=Find(v);
            if(fu==fv||fv!=v)flag=0;
            else f[v]=fu;
        }
        if(nume==tot-1&&flag)printf("Case %d is a tree.\n",++cas);
        else printf("Case %d is not a tree.\n",++cas);
    }
    return 0;
}