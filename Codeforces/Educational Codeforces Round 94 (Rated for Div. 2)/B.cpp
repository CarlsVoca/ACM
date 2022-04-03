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
        LL p,f,cnts,cntw,s,w;
        scanf("%lld%lld%lld%lld%lld%lld",&p,&f,&cnts,&cntw,&s,&w);
        LL ans=0;
        rep(i,0,cnts){
            if(i*s>p)break;
            LL tmpp=p,tmpf=f,t1=cnts,t2=cntw;
            LL res=i;tmpp-=i*s;t1-=i;
            LL tmp=min(tmpp/w,t2);
            res+=tmp;tmpp-=tmp*w;t2-=tmp;
            if(s<w){
                tmp=min(tmpf/s,t1);
                res+=tmp;tmpf-=tmp*s;t1-=tmp;
                tmp=min(tmpf/w,t2);
                res+=tmp;tmpf-=tmp*w;t2-=tmp;
            }
            else{
                tmp=min(tmpf/w,t2);
                res+=tmp;tmpf-=tmp*w;t2-=tmp;
                tmp=min(tmpf/s,t1);
                res+=tmp;tmpf-=tmp*s;t1-=tmp;
            }
            ans=max(ans,res);
        }
        printf("%lld\n",ans);
    }
    return 0;
}