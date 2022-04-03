#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    string ss;
    cin>>ss;
    int cntc=0,cntb=0,cnts=0;
    int n=ss.length();
    rep(i,0,n-1){
        if(ss[i]=='C')cntc++;
        else if(ss[i]=='B')cntb++;
        else cnts++;
    }
    LL c,b,s;
    scanf("%lld%lld%lld",&b,&s,&c);
    LL q,w,e;
    scanf("%lld%lld%lld",&w,&e,&q);
    LL tot;
    scanf("%lld",&tot);
    LL l=0,r=1e15;
    while(l<r){
        LL mid=(l+r>>1)+1;
        if(max(cntc*mid-c,0LL)*q+max(cntb*mid-b,0LL)*w+max(cnts*mid-s,0LL)*e<=tot)l=mid;
        else r=mid-1;
    }
    printf("%lld\n",l);
    return 0;
}