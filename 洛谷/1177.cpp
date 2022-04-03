#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

namespace Radix_Sort{
	const int base=1<<16;
	vector<int>r[base];
	void do_main(int arr[],int size){
		bool flag=1;
		LL d=base;
		while(flag){
			flag=0;
			for(int i=1;i<=size;i++){
				r[(arr[i]/(d/base))%d].push_back(arr[i]);
				if(arr[i]/d)flag=1;	
			}
			int cnt=0;
			for(int i=0;i<base;i++){
				for(int j=0;j<r[i].size();j++){
					arr[++cnt]=r[i][j];
				}
			}
			d*=base;
			for(int i=0;i<base;i++)r[i].resize(0);
		}
	}
}
using namespace Radix_Sort;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    do_main(a,n);
    rep(i,1,n)printf("%d ",a[i]);
    return 0;
}