#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v){puts("NO");continue;}
        int cntu=0,cntv=0;
        bool flag=1;
        while(u||v){
            if(u&1)cntu++;
            if(v&1)cntv++;
            if(cntv>cntu){flag=0;break;}
            u>>=1;
            v>>=1;
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}