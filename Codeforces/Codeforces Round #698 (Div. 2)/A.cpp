#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        int cnt=1,ans=1;
        rep(i,2,n){
            if(a[i]==a[i-1])cnt++;
            else ans=max(cnt,ans),cnt=1;
        }
        ans=max(cnt,ans);
        printf("%d\n",ans);
    }
    return 0;
}