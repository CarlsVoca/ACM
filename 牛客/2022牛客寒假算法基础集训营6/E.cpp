#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int a[maxn],b[maxn],h[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int MAX=0,MAXX=0,MAXpos=-1,MAXXpos=-1;
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d%d%d",&a[i],&b[i],&h[i]);
            if(a[i]>=MAX){
                MAXX=MAX;
                MAXXpos=MAXpos;
                MAX=a[i];
                MAXpos=i;
            }
            else if(a[i]>MAXX){
                MAXX=a[i];
                MAXXpos=i;
            }
        }
        LL ans=0;
        rep(i,1,n){
            if(i!=MAXpos){
                ans+=max(0,MAX-b[i]-h[i]+1);
            }
            else{
                ans+=max(0,MAXX-b[i]-h[i]+1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}