#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];
int n,k,L;

namespace Binary_Search{
    bool check(int ans){
        int cnt=0;
        rep(i,2,n){
            if(a[i]-a[i-1]>ans){
                cnt+=(a[i]-a[i-1]-1)/ans;
            }
            if(cnt>k)break;
        }
        return cnt<=k;
    }
    int do_main(){
        int l=1,r=L;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        return l;
    }
}
using namespace Binary_Search;

int main(){
    scanf("%d%d%d",&L,&n,&k);
    rep(i,1,n)scanf("%d",&a[i]);
    printf("%d\n",do_main());
    return 0;
}