#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

int L,n,m;
int a[maxn];

namespace Binary_Answer{
	bool check(int ans){
		int cnt=0,pre=0;
		for(int i=1;i<=n+1;i++){
			if(a[i]-pre<ans){
				if(++cnt>m)return 0;
			}
			else pre=a[i];
		}
		return 1;
	}
	int do_main(){
		int l=0,r=L;
		while(l<r){
			int mid=(l+r>>1)+1;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		return l;
	}
}

int main()
{
	scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=L;
    printf("%d",Binary_Answer::do_main());
    return 0;
}