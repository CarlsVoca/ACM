#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=100005;

int a[maxn];
LL sum[maxn];

namespace Discretization{
	int tmp[maxn],m;
	void do_main(int arr[],int size){
		memcpy(tmp+1,arr+1,size<<2);//int:?=2;long long:?=4;
		sort(tmp+1,tmp+size+1);
		m=unique(tmp+1,tmp+size+1)-tmp-1;
		for(int i=1;i<=size;i++)arr[i]=lower_bound(tmp+1,tmp+m+1,arr[i])-tmp;
	}
}
using namespace Discretization;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        LL ans=0;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        do_main(a,n);
        rep(i,1,n)sum[i]=0;
        rep(i,1,n){
            ans+=(n-i+1)*sum[a[i]];
            sum[a[i]]+=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}