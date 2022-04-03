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
        int x=0,y=0;
        int n;
        scanf("%d",&n);
        double ans=0;
        rep(i,1,n){
            char op;
            cin>>op;
            if(op=='L')x--;
            if(op=='R')x++;
            if(op=='U')y++;
            if(op=='D')y--;
            ans=max(ans,sqrt(1.0*x*x+y*y));
        }
        printf("%.12lf\n",ans);
    }
    return 0;
}