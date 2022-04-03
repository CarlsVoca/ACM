#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=105;
const double eps=1e-6;

int d[maxn],h[maxn],n,D,H;

bool check(double i){
    rep(j,1,n){
        if(h[j]>(H-i)/D*d[j]+i)return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d%d",&n,&D,&H);
    rep(i,1,n)scanf("%d%d",&d[i],&h[i]);
    double l=0,r=1000;
    while(r-l>eps){
        double mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    printf("%lf\n",l);
    return 0;
}