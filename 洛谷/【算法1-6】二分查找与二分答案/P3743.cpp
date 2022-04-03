#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int n,p;
int a[maxn],b[maxn];
double sum=0;

namespace Binary_Search{
    double EPS=1e-6;
    bool check(double ans){
        double res=ans*p;
        rep(i,1,n)res+=min(b[i]*1.0/a[i],ans)*a[i];
        return res>=ans*sum;
    }
    double do_main(){
        double l=0,r=1e10;
        while(r-l>EPS){
            double mid=(l+r)/2;
            if(check(mid))l=mid;
            else r=mid;
        }
        return l;
    }
}
using namespace Binary_Search;

int main(){
    scanf("%d%d",&n,&p);
    rep(i,1,n)scanf("%d%d",&a[i],&b[i]),sum+=a[i];
    if(sum<=p)puts("-1");
    else printf("%lf\n",do_main());
    return 0;
}