#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=5e5+5;

int a[maxn];
LL sta[maxn][2];
int n,tp=0;

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    a[0]=INF;a[n+1]=INF;
    LL MAX=0;
    rep(i,0,n+1){
        while(tp&&sta[tp][1]<a[i]){
            MAX+=(sta[tp][0]-sta[tp-1][0])*(i-sta[tp][0])*sta[tp][1];
            tp--;
        }
        sta[++tp][0]=i;sta[tp][1]=a[i];
    }
    tp=0;
    a[0]=-INF;a[n+1]=-INF;
    LL MIN=0;
    rep(i,0,n+1){
        while(tp&&sta[tp][1]>a[i]){
            MIN+=(sta[tp][0]-sta[tp-1][0])*(i-sta[tp][0])*sta[tp][1];
            tp--;
        }
        sta[++tp][0]=i;sta[tp][1]=a[i];
    }
    printf("%lld\n",MAX-MIN);
    return 0;
}