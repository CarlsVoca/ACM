#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=1e6+5;
const LL INF=(1LL<<60);

struct Edge{
	int u,v;
}e[maxn];

int a[maxn];

int sz[maxn];
LL val[maxn];
int f[maxn];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

int main(){
	freopen("test.in","r",stdin);
	freopen("std.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		LL SUM=0;
		rep(i,1,n)scanf("%d",&a[i]),SUM+=a[i];
		rep(i,1,m){
			scanf("%d%d",&e[i].u,&e[i].v);
		}
		if(n%2==0){
			printf("%lld\n",SUM);
			continue;
		}
		LL ans=-INF;
		rep(i,1,n){
			rep(j,1,n)val[j]=a[j],sz[j]=1,f[j]=j;
			rep(j,1,m){
				if(e[j].u==i||e[j].v==i)continue;
				int fx=find(e[j].u),fy=find(e[j].v);
				if(fx==fy)continue;
				f[fx]=fy;
				sz[fy]+=sz[fx];
				val[fy]+=val[fx];
			}
			LL res=0;
			rep(j,1,n){
				if(find(j)==j){
					res+=((sz[j]&1)?-1:1)*val[j];
				}
			}
			ans=max(res,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}