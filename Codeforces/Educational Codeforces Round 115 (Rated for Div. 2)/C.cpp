#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

double a[maxn];
map<double,int> cnt;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cnt.clear();
        int n;
        scanf("%d",&n);
        double sum=0;
        rep(i,1,n)scanf("%lf",&a[i]),sum+=a[i];
        double k=sum/n;
        LL ans=0;
        rep(i,1,n){
            double b=2*k-a[i];
            ans+=cnt[b];
            cnt[a[i]]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}