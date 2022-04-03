#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
    
int n,m,k;

namespace Binary_Search{
    double EPS=1e-6;
    bool check(double ans){
        double p=1+ans,res=0;
        rep(i,1,k){
            res+=m/p;
            p*=(1+ans);
        }
        return res<n;
    }
    double do_main(){
        double l=0,r=100;
        while(r-l>EPS){
            double mid=(l+r)/2;
            if(check(mid))r=mid;
            else l=mid;
        }
        return l;
    }
}
using namespace Binary_Search;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    printf("%.1lf\n",do_main()*100);
    return 0;
}