#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int MOD=998244353;
const int maxn=100005;
const int INF=0x3f3f3f3f;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int pre=-INF,ans=0;
        rep(i,1,n){
            if(a[i]-k>pre){
                pre=a[i]-k;
                ans++;
            }
            else{
                if(pre>=a[i]+k)continue;
                else{
                    pre++;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}