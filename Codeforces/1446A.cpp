#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

struct Data{
    LL a;
    int id;
    bool operator < (const Data &d)const{
        return a<d.a;
    }
}d[maxn];

int main(){
    int T;
    scanf("%d",&T);
    testcase:while(T--){
    int n;
    LL W;
    scanf("%d%lld",&n,&W);
    rep(i,1,n)scanf("%lld",&d[i].a),d[i].id=i;
    sort(d+1,d+n+1);
    LL sum=0;
    int cnt=0;
    rep(i,1,n){
        if(d[i].a<(W+1)/2){
            sum+=d[i].a;
            if(sum>=(W+1)/2){cnt=i;break;}
        }
        else if(d[i].a<=W&&d[i].a>=(W+1)/2){
            printf("1\n%d\n",d[i].id);
            goto testcase;
        }
        else break;
    }
    if(!cnt)puts("-1");
    else{
        printf("%d\n",cnt);
        rep(i,1,cnt){
            printf("%d ",d[i].id);
        }
    }
    }
    return 0;
}