#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    // freopen("14.in","r",stdin);
    // freopen("14.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        LL n,m;
        scanf("%lld%lld",&n,&m);
        LL b=sqrt(n);
        LL ans=0;
        if(m<=b){
            ans+=n-1;//L
            ans+=(n-1)*m;//R
        }
        else if(m<2*b){
            ans+=n-1;//L
            ans+=(n-1)*b;//R
            m-=b;
            ans+=2*(b-1)*m;//L
            ans+=(n-1)*m;//R
        }
        else if(m==2*b){
            ans+=n-1;//L
            ans+=(n-1)*b;//R
            m-=b;
            ans+=2*(b-1)*(b-1);//L
            ans+=(n-1)*(b-1);//R
            m-=b-1;
            ans+=2*(b-1);//L
        }
        else{
            ans+=n-1;//L
            ans+=(n-1)*b;//R
            m-=b;
            ans+=2*(b-1)*(b-1);//L
            ans+=(n-1)*(b-1);//R
            m-=b-1;
            ans+=2*(b-1);//L
            m--;
            ans+=2*(b-1)*(m/2);//L
        }
        printf("%lld\n",ans);
    }
    return 0;
}