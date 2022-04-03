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
        int n,m,rb,cb,rd,cd;
        scanf("%d%d%d%d%d%d",&n,&m,&rb,&cb,&rd,&cd);
        int ans=0;
        int dx=1,dy=1;
        while(rb!=rd&&cb!=cd){
            if(rb+dx>n||rb+dx<1)dx=-dx;
            if(cb+dy>m||cb+dy<1)dy=-dy;
            rb+=dx;
            cb+=dy;
            ans++;
            // printf("%d %d\n",rb,cb);
            // system("pause");
        }
        printf("%d\n",ans);
    }
    return 0;
}