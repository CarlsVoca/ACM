#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const double eps=1e-4;

int main(){
    double h,s,v,l,k;
    int n;
    scanf("%lf%lf%lf%lf%lf%d",&h,&s,&v,&l,&k,&n);
    double L=(s-sqrt(h/5)*v-eps),R=(s-(sqrt((h-k)/5)*v-l)+eps);
    L=max(L,0.0);
    R=min(R,n-1.0);
    printf("%d\n",max(0,(int)floor(R)-(int)ceil(L)+1));
    return 0;
}