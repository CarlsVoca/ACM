#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=100005;

int n;

namespace Binary_Indexed_Tree{
	int c[maxn];
	void Change(int x,int k){
		for(;x<=n;x+=x&-x)c[x]+=k;
	}
	int Query(int x){
		int res=0;
		for(;x;x-=x&-x)res+=c[x];
		return res;
	}
}
using namespace Binary_Indexed_Tree;

namespace Discretization{
	int tmp[maxn];
	void do_main(int arr[],int size){
		memcpy(tmp+1,arr+1,size<<2);
		sort(tmp+1,tmp+size+1);
		int m=unique(tmp+1,tmp+size+1)-tmp-1;
		for(int i=1;i<=size;i++)arr[i]=lower_bound(tmp+1,tmp+m+1,arr[i])-tmp;
	}
}
using namespace Discretization;

int s[maxn],pos[maxn];

int main(){
	memset(c,0,sizeof(c));
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	n=n1+n2;
	for(int i=n1;i>=1;i--)scanf("%d",&s[i]);
	for(int i=n1+1;i<=n1+n2;i++)scanf("%d",&s[i]);
	do_main(s,n);
	for(int i=1;i<=n;i++)pos[s[i]]=i;
	for(int i=1;i<=n;i++)Change(i,1);
	int p=n1;
	LL ans=0;
	for(int i=n;i>=1;i--){
		if(p==pos[i]||p==pos[i]-1){
			Change(pos[i],-1);
			continue;
		}
		if(p>pos[i]){
			ans+=Query(p)-Query(pos[i]);
			p=pos[i];
		}
		else if(p<pos[i]-1){
			ans+=Query(pos[i]-1)-Query(p);
			p=pos[i]-1;
		}
		Change(pos[i],-1);
	}
	printf("%lld\n",ans);
	return 0;
}