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
        int n,u,v;
        scanf("%d%d%d",&n,&u,&v);
        rep(i,1,n)scanf("%d",&a[i]);
        int MAX=0;
        rep(i,2,n){
            MAX=max(MAX,abs(a[i]-a[i-1]));
        }
        if(MAX==0)printf("%d\n",min(u+v,v+v));
        else if(MAX==1)printf("%d\n",min(u,v));
        else puts("0");
    }
    return 0;
}