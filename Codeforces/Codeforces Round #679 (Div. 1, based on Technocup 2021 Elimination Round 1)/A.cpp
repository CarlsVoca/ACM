#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[10],b[maxn],cnt[maxn];

struct Data{
	int id,val;
	bool operator < (const Data &b)const{
		return val<b.val;
	}
}c[maxn*6];

int main(){
	rep(i,1,6)scanf("%d",&a[i]);
	int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&b[i]);
	sort(a+1,a+7);
	rep(i,1,n){
		rep(j,1,6){
			c[i+(j-1)*n].val=b[i]-a[j];
			c[i+(j-1)*n].id=i;
		}
	}
	sort(c+1,c+6*n+1);
	int r=0,tot=0;
	while(tot<n){
		cnt[c[++r].id]++;
		if(cnt[c[r].id]==1)tot++;
	}
	int l=1;
	while(cnt[c[l].id]-1!=0)cnt[c[l++].id]--;
	int ans=c[r].val-c[l].val;
	while(r<6*n){
		cnt[c[++r].id]++;
		while(cnt[c[l].id]-1!=0)cnt[c[l++].id]--;
		ans=min(ans,c[r].val-c[l].val);
	}
	printf("%d\n",ans);
	return 0;
}