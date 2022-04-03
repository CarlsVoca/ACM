#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=105;

int a[maxn][maxn],b[maxn][maxn];
vector<int> v1,v2;
bool pos[maxn<<1];
int n;

int random(int MIN,int MAX){
    return rand()%(MAX-MIN+1)+MIN;
}

namespace Simulate_Anneal{
	const double eps=1e-6;
	bool accept(LL delta,double temper){
		if(delta>=0)return 1;
		return rand()<exp(delta/temper)*RAND_MAX;
	}
    LL f(){
        int x=1,y=1;
        LL cnt=a[x][y],val=b[x][y];
        rep(i,1,2*n-2){
            if(!pos[i])x++;
            else y++;
            cnt+=a[x][y];val+=b[x][y];
        }
        return cnt*val;
    }
    int tmp[maxn<<1];
	LL solve(){
        v1.clear();v2.clear();
		double t=100000000,del=0.9999;
        rep(i,1,2*n-2)tmp[i]=i;
        random_shuffle(tmp+1,tmp+2*n-2+1);
		rep(i,1,n-1)v1.push_back(tmp[i]),pos[tmp[i]]=0;
        rep(i,n,2*n-2)v2.push_back(tmp[i]),pos[tmp[i]]=1;
        LL res=f();
		while(t>eps){
			int x=random(0,n-2),y=random(0,n-2);
            swap(pos[v1[x]],pos[v2[x]]);
            swap(v1[x],v2[x]);
			LL newres=f();
            if(accept(newres-res,t))res=newres;
			else{
                swap(pos[v1[x]],pos[v2[y]]);
                swap(v1[x],v2[y]);
            }
            t*=del;
		}
		return res;
	}
	LL do_main(){
		srand(time(0));
		LL res=0;
		int T=150;
		while(T--){
			res=max(res,solve());
		}
		return res;
	}
}
using namespace Simulate_Anneal;

int main(){
    freopen("test.in","r",stdin);
    clock_t st=clock();
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
        rep(i,1,n)rep(j,1,n)scanf("%d",&b[i][j]);
        printf("%lld\n",do_main());
    }
    clock_t ed=clock();
    printf("used time=%lf\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}