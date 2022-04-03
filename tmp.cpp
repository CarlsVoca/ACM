#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;

int a[maxn],ans[maxn];
int n;

namespace MP{
	int f[maxn];
	void Get_Fail(int *P){
		f[1]=0;
		for(int i=2;i<=n;i++){
			int j=f[i-1];
			while(j&&P[j+1]!=P[i])j=f[j];
			f[i]=P[j+1]==P[i]?j+1:0;
		}
	}
}
using namespace MP;

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    Get_Fail(a);
    rep(i,1,n){
        ans[i]=ans[f[i]]+1;
        printf("%d ",ans[i]);
    }
    return 0;
}