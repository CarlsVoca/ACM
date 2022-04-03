#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=(1LL<<60);

LL a,b,c,d;
int n;

namespace Simulate_Anneal{
	const double eps=1e-9;
	bool accept(LL delta,int temper){
		if(delta>=0)return 1;
		return rand()<exp(delta*1.0/temper)*RAND_MAX;
	}
    LL f(int x){
        /* 对状态x进行估价，应该使估价值的数量级较大 */
        int g=0,tmp=x;
        while(tmp){
            g+=tmp%10;
            tmp/=10;
        }
        return a*x*x*g+b*x*x+c*x*g*g+d*x*g;
    }
    int random(int MIN,int MAX){
        return rand()%(MAX-MIN+1)+MIN;
    }
	LL solve(){
		int t=n;
        double del=0.99999;
		int plan=random(1,n);
		while(t>1){
			int newplan=plan+((rand()&1)?1:-1)*t;
            if(newplan<1||newplan>n){t*=del;continue;}
			if(accept(f(plan)-f(newplan),t))plan=newplan;
			t*=del;
		}
		return f(plan);
	}
	LL do_main(){
		srand(20010817);
		LL res=INF;
		int T=100;//退火次数，可小一些
		while(T--){
			res=min(res,solve());
		}
		return res;
	}
}
using namespace Simulate_Anneal;

int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld%d",&a,&b,&c,&d,&n);
        printf("%lld\n",do_main());
    }
    return 0;
}