#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const double eps=1e-6;

int main(){
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    rep(i,-10000,10000){
        double x=i*0.01;
        if(fabs(a*x*x*x+b*x*x+c*x+d)<eps)printf("%.2lf ",x);
    }
    return 0;
}