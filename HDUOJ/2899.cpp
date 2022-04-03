#include<bits/stdc++.h>

using namespace std;

const double INF=1e300;

double y;

double f(double x){
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}

namespace Simulate_Anneal{
    const double eps=1e-9;
    bool accept(double delta,double temper){
        if(delta>=0)return 1;
        return rand()<exp(delta/temper)*RAND_MAX;
    }
    double solve(){
        double t=100,del=0.99;
        double x=rand()*100.0/RAND_MAX;
        while(t>eps){
            double newx=x+(((double)rand()/RAND_MAX)*2-1)*t;
            if(newx<0||newx>100){t*=del;continue;}
            if(accept(f(x)-f(newx),t))x=newx;
            t*=del;
        }
        return f(x);
    }
    double do_main(){
        srand(20010817);
        double res=INF;
        int T=10;
        while(T--){
            res=min(res,solve());
        }
        return res;
    }
}
using namespace Simulate_Anneal;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lf",&y);
        printf("%.4lf\n",do_main());
    }
    return 0;
}