#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int l[maxn],r[maxn];
bool vis[maxn];

int main(){
	int n;
	scanf("%d",&n);
	r[0]=1,l[1]=0,r[1]=n+1,l[n+1]=1;
	for(int i=2;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y==0)r[l[x]]=i,l[i]=l[x],r[i]=x,l[x]=i;
		else l[r[x]]=i,r[i]=r[x],l[i]=x,r[x]=i;
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		if(vis[x])continue;
		else{
			r[l[x]]=r[x];l[r[x]]=l[x];
			vis[x]=1;
		}
	}
	for(int pos=r[0];pos!=n+1;pos=r[pos]){
		if(r[pos]!=n+1)printf("%d ",pos);
		else printf("%d\n",pos);
	}
	return 0;
}