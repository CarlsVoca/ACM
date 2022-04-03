#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

double a[maxn][maxn];
int ans[maxn],sb;
int ANS[maxn];
int n;

namespace Simulate_Anneal{
    const double eps=1e-9;
    bool accept(double delta,double temper){
        if(delta>=0)return 1;
        return rand()<exp(delta/temper)*RAND_MAX;
    }
    int random(int MIN,int MAX){
        return MIN+rand()%(MAX-MIN+1);
    }
    double solve(){
        double t=1000,del=0.999;
        double sum=0;
        rep(i,1,n){
            ans[i]=i;
            sum+=a[i][i];
        }
        while(t>eps){
            int x=random(1,n);
            int y=(x+random(1,n-1)-1)%n+1;
            double newsum=sum-a[ans[x]][x]-a[ans[y]][y]+a[ans[y]][x]+a[ans[x]][y];
            if(accept(newsum-sum,t)){
                sum=newsum;
                swap(ans[x],ans[y]);
            }
            t*=del;
        }
        return sum;
    }
    double do_main(){
        srand(20010817);
        double res=0;
        sb=clock();
        // printf("%d\n",CLOCKS_PER_SEC);
        rep(i,1,n)ANS[i]=i;
        while((clock()-sb)<=800){
            double tmp=solve();
            if(res<tmp){
                res=tmp;
                rep(i,1,n)ANS[i]=ans[i];
            }
        }
        return res;
    }
}
using namespace Simulate_Anneal;

int main(){
    srand(time(0));
    scanf("%d",&n);
    rep(i,1,n){
        rep(j,1,n){
            scanf("%lf",&a[i][j]);
            a[i][j]=log2(a[i][j]*1000000000);
        }
    }
    // printf("%lf\n",do_main());
    do_main();
    rep(i,1,n)printf("%d ",ANS[i]);
    return 0;
}