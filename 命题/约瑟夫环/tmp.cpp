#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll n,m,sb;
int main(){
    clock_t st=clock();
    freopen("11.in","r",stdin);
    freopen("11.tmp","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		if(m>2&&n%(m-1)!=1){puts("NO");continue;}
		for(sb=1;sb*m<=n;sb*=m){}
		printf("YES\n%lld\n",(sb==n)?n:(n-sb)/(m-1)*m);
	}
    clock_t ed=clock();
    printf("used time=%lf\n",(double)(ed-st)/CLOCKS_PER_SEC);
}