#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

struct M{
    double x,y,z;
    bool operator < (M &b)const{
        return z<b.z;
    }
}a[maxn];

double L(M a,M b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+n+1);
    double ans=0;
    rep(i,2,n){
        ans+=L(a[i],a[i-1]);
    }
    printf("%.3lf\n",ans);
    return 0;
}