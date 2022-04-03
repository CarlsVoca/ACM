#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=5005;

LL A[maxn*maxn];
LL C[maxn][maxn];
LL minc[maxn],minr[maxn];
vector<int> vec;

int main(){
    // clock_t st=clock();
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
	// int n,m,a,b,c,d,p;
	// scanf("%d%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d,&p);
	// A[0]=a;
	// rep(i,1,n*m)A[i]=(A[i-1]*A[i-1]%p*b%p+A[i-1]*c%p+d)%p;
	LL ans=0;
	// rep(i,1,n)rep(j,1,m){
	// 	C[i][j]=A[m*(i-1)+j];
	// 	ans+=C[i][j];
	// }
	// rep(i,1,n){
	// 	rep(j,1,m){
	// 		printf("%d ",C[i][j]);
	// 	}
	// 	putchar('\n');
	// }
    rep(i,1,n)rep(j,1,m)scanf("%d",&C[i][j]),ans+=C[i][j];
	rep(i,1,n){
		minr[i]=C[i][1];
		rep(j,2,m){
			minr[i]=min(minr[i],C[i][j]);
		}
	}
	rep(j,1,m){
		minc[j]=C[1][j];
		rep(i,2,n){
			minc[j]=min(minc[j],C[i][j]);
		}
	}
	rep(j,1,m-1){
		LL res=0;
		vec.clear();
		rep(i,1,n){
			if(C[i][j]<C[i][j+1])res+=C[i][j],vec.push_back(C[i][j+1]);
			else res+=C[i][j+1],vec.push_back(C[i][j]);
		}
		sort(vec.begin(),vec.end());
		res+=vec[0];
		rep(k,1,m){
			if(k==j||k==j+1)continue;
			res+=minc[k];
		}
		ans=min(res,ans);
	}
	rep(i,1,n-1){
		LL res=0;
		vec.clear();
		rep(j,1,m){
			if(C[i][j]<C[i+1][j])res+=C[i][j],vec.push_back(C[i+1][j]);
			else res+=C[i+1][j],vec.push_back(C[i][j]);
		}
		sort(vec.begin(),vec.end());
		res+=vec[0];
		rep(k,1,n){
			if(k==i||k==i+1)continue;
			res+=minr[k];
		}
		ans=min(res,ans);
	}
	printf("%lld\n",ans);
    // clock_t ed=clock();
    // printf("used time=%lf\n",(double)(ed-st)/CLOCKS_PER_SEC);
	return 0;
}