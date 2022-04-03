#include<bits/stdc++.h>

using namespace std;

typedef long long LL; 

const int maxn=100005;

void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

struct Edge{
	int v,nxt;
}e[maxn*2];
int nume;

struct Node{
	int l,r;
	LL sum;
    vector<LL> lazy;
}t[maxn*4];
int numn;

int size[maxn],last[maxn],son[maxn],top[maxn],id[maxn],rel[maxn];
int n,m,R=1;

namespace LCA{
	int dep[maxn],f[maxn][22];
	void pre(){
		for(int j=1;(1<<j)<=n;j++)
			for(int i=1;i<=n;i++){
				f[i][j]=f[f[i][j-1]][j-1];
			}
	}
	int do_main(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		int dif=dep[a]-dep[b];
		for(int i=0;(1<<i)<=dif;i++){
			if((1<<i)&dif)a=f[a][i];
		}
		if(a!=b){
			for(int i=(int)log2(n);i>=0;i--){
				if(f[a][i]!=f[b][i]){
					a=f[a][i];b=f[b][i];
				}
			}
			a=f[a][0];b=f[b][0];
		}
		return a;
	}
}
using namespace LCA;

void add_edge(int u,int v)
{
	e[++nume].nxt=last[u];
	last[u]=nume;
	e[nume].v=v;
}

void DFS_1(int u)
{
	size[u]=1;
	for(int i=last[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==f[u][0])continue;
		f[v][0]=u;
		dep[v]=dep[u]+1;
		DFS_1(v);
		size[u]+=size[v];
		if(size[v]>=size[son[u]]){
			son[u]=v;
		}
	}
}

void DFS_2(int u,int tp)
{
	top[u]=tp;
	id[u]=++numn;
	rel[numn]=u;
	if(son[u])DFS_2(son[u],tp);
	for(int i=last[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==f[u][0]||v==son[u])continue;
		DFS_2(v,v);
	}
}

void build(int k1,int l,int r)
{
	t[k1].l=l;t[k1].r=r;
	if(l==r){
		t[k1].sum=0;
		return;
	}
	int mid=l+r>>1;
	build(k1<<1,l,mid);
	build(k1<<1|1,mid+1,r);
}

void pushdown(int k1)
{
	if(t[k1].r==t[k1].l)return;
    for(int i=0;i<t[k1].lazy.size();i++)t[k1<<1].lazy.push_back(t[k1].lazy[i]);
	for(int i=0;i<t[k1].lazy.size();i++)t[k1<<1|1].lazy.push_back(t[k1].lazy[i]+t[k1<<1].r-t[k1<<1].l+1);
    if(t[k1<<1].r==t[k1<<1].l){
        for(int i=0;i<t[k1].lazy.size();i++)t[k1<<1].sum+=t[k1].lazy[i]*t[k1].lazy[i];
    }
    if(t[k1<<1|1].r==t[k1<<1|1].l){
        for(int i=0;i<t[k1].lazy.size();i++)t[k1<<1|1].sum+=(t[k1].lazy[i]+t[k1<<1].r-t[k1<<1].l+1)*(t[k1].lazy[i]+t[k1<<1].r-t[k1<<1].l+1);
    }
	t[k1].lazy.clear();
}

void change_interval(int k1,int l,int r,LL k)
{
	if(t[k1].r<l||t[k1].l>r) return;
	if(t[k1].l>=l&&t[k1].r<=r){
		if(t[k1].l==t[k1].r){
            t[k1].sum+=k*k;
        }
        else t[k1].lazy.push_back(k);
		return;
	}
	pushdown(k1);
	change_interval(k1<<1,l,r,k);
	change_interval(k1<<1|1,l,r,k+t[k1<<1].r-t[k1<<1].l+1);
}

LL query(int k1,int l,int r)
{
	if(t[k1].r<l||t[k1].l>r)return 0;
	if(t[k1].l>=l&&t[k1].r<=r){
		return t[k1].sum;
	}
	pushdown(k1);
	return (query(k1<<1,l,r)+query(k1<<1|1,l,r));
}

void change_road(int u, int v)
{
	int tp1=top[u],tp2=top[v];
	while(tp1!=tp2){
		if(dep[tp1]<dep[tp2])swap(tp1,tp2),swap(u,v);
		change_interval(1,id[tp1],id[u],x);
		u=f[tp1][0];
		tp1=top[u];
	}
	if(dep[u]>dep[v])swap(u,v);
	change_interval(1,id[u],id[v],x);
}

LL query_point(int u)
{
	return query(1,id[u],id[u]);
}

int main()
{
	read(n);read(m);
	int u,v;
	for(int i=1;i<=n-1;i++){
		read(u);read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	DFS_1(R);
	DFS_2(R,R);
	build(1,1,n);
    pre();
	int tp,x,y;
	for(int i=1;i<=m;i++){
		read(tp);
		if(tp==1){
			read(x);read(y);
			change_road(x,y);
		}
		if(tp==2){
			read(x);
			printf("%lld\n",query_point(x));
		}
	}
	return 0;
}