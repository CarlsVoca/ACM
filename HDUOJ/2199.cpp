#include<bits/stdc++.h>

using namespace std;

const double INF=1e300;

double y;

double f(double x){
    return fabs(8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6-y);
}

namespace Simulate_Anneal{
    const double eps=1e-5;
    bool accept(double delta,double temper){
        if(delta>=0)return 1;
        return rand()<exp(delta/temper)*RAND_MAX;
    }
    double solve(){
        double t=100,del=0.98;
        double x=rand()*100.0/RAND_MAX;
        while(t>eps){
            double newx=x+(((double)rand()/RAND_MAX)*2-1)*t;
            if(newx<0||newx>100){t*=del;continue;}
            if(accept(f(x)-f(newx),t))x=newx;
            t*=del;
        }
        return x;
    }
    double do_main(){
        srand(20010817);
        double res=f(0),ans=0;
        int T=50;
        while(T--){
            double x=solve();
            if(f(x)<res){
                res=f(x);
                ans=x;
            }
        }
        return ans;
    }
}
using namespace Simulate_Anneal;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lf",&y);
        double ans=do_main();
        if(f(ans)>1e-1)puts("No solution!");
        else printf("%.4lf\n",ans);
    }
    return 0;
}