#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

bool judge(int x,int d){
    while(x){
        if(x%10==d)return 1;
        x/=10;
    }
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int q,d;
        scanf("%d%d",&q,&d);
        rep(i,1,q){
            int x;
            scanf("%d",&x);
            if(d==1)puts("YES");
            else{
                int cnt=x/d;
                if(x%d==0)puts("YES");
                else{
                    int y=x%d;
                    bool flag=0;
                    for(int j=1;j<=1000&&y+d*j<=x;j++){
                        if(judge(y+j*d,d)){flag=1;break;}
                    }
                    if(flag)puts("YES");
                    else puts("NO");
                }
            }
        }
    }
    return 0;
}