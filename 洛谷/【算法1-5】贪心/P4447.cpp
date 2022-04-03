#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn],p[maxn],tp=0,sz[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    p[0]=INF;
    rep(i,1,n){
        int pos=upper_bound(p+1,p+tp+1,a[i])-p;
        if(p[pos-1]!=a[i]){
            tp++;
            p[tp]=a[i]+1;
            sz[tp]=1;
        }
        else{
            p[pos-1]++;
            sz[pos-1]++;
        }
    }
    int ans=INF;
    rep(i,1,tp)ans=min(ans,sz[i]);
    printf("%d\n",ans);
    return 0;
}