#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,H;
        scanf("%d%d",&n,&H);
        int MAX1=0,MAX2=0;
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            if(x>MAX1){
                MAX2=MAX1;
                MAX1=x;
            }
            else if(x>MAX2){
                MAX2=x;
            }
        }
        int ans=0;
        ans+=(H-1)/(MAX1+MAX2)*2;
        int res=H-ans/2*(MAX1+MAX2);
        if(res>0&&res<=MAX1)ans++;
        else if(res>MAX1)ans+=2;
        printf("%d\n",ans);
    }
    return 0;
}