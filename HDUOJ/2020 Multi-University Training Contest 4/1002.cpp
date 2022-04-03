#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int a[maxn],d[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d%d",&a[i],&d[i]);
        double ans=0;
        rep(i,1,n){
            double res=0;
            rep(j,1,n){
                int ti=ceil(100.0/a[i]-1)*d[i],tj=ceil(100.0/a[j]-1)*d[j];
                if(ti==tj)res+=0.5;
                else if(ti<tj)res+=1;
            }
            ans=max(ans,res/n);
        }
        printf("%lf\n",ans);
    }
    return 0;
}