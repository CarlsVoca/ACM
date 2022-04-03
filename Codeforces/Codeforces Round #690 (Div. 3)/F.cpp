#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

struct Line{
    int l,r;
}l[maxn];

int ll[maxn],rr[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d%d",&l[i].l,&l[i].r),ll[i]=l[i].l,rr[i]=l[i].r;
        sort(ll+1,ll+n+1);
        sort(rr+1,rr+n+1);
        int ans=INF;
        rep(i,1,n){
            int res=0;
            int tmp1=lower_bound(rr+1,rr+n+1,l[i].l)-rr;
            res+=tmp1-1;
            int tmp2=upper_bound(ll+1,ll+n+1,l[i].r)-ll;
            if(ll[tmp2]>l[i].r)res+=n-tmp2+1;
            else res+=0;
            ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}