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
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=0;
        if(n==m)ans=1;
        else if(m==1){
            puts("-1");
            continue;
        }
        else{
            n-=m;
            ans+=((n+m-2)/(m-1))*2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}