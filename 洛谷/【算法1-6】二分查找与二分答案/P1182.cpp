#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn];
int n,m,MAX=0;

namespace Binary_Answer{
	bool check(int ans){
		int sum=0;
		int tmp=m-1;
		for(int i=1;i<=n;i++){
			while(sum+a[i]>ans){
				sum=0;
				tmp--;
				if(tmp<0)return 0;
			}
			sum+=a[i];
		}
		return 1;
	}
	int do_main(){
		int l=0,r=MAX;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		return l;
	}
}
using namespace Binary_Answer;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),MAX+=a[i];
	printf("%d\n",do_main());
	return 0;
}