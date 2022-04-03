#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const int maxn=2e5+5;

namespace Quick_Pow{
    LL do_main(LL a,int k){
        // cout<<a<<" "<<k<<endl;
        LL r=1,base=a;
        while(k){
            if(k&1)r=(r*base)%MOD;
            base=(base*base)%MOD;
            k>>=1;
        }
        return r%MOD;
    }
}
using namespace Quick_Pow;

multiset<int> s[maxn];
map<int,int> cnt[maxn];
int a[maxn];

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    rep(i,1,n){
        scanf("%d",&a[i]);
        int tmp=a[i];
        for(int j=2;1LL*j*j<=tmp;j++){
            while(tmp%j==0){
                cnt[i][j]++;
                tmp/=j;
            }
        }
        if(tmp!=1)cnt[i][tmp]++;
        for(auto j:cnt[i])s[j.first].insert(j.second);
    }
    LL g=a[1];
    rep(i,2,n)g=__gcd(g,(LL)a[i]);
    while(q--){
        int pos,val;
        scanf("%d%d",&pos,&val);
        int tmp=val;
        for(int j=2;1LL*j*j<=tmp;j++){
            if(tmp%j!=0)continue;
            int cntt=0;
            while(tmp%j==0){
                tmp/=j;
                cntt++;
            }
            int pre=0;
            if(s[j].size()==n)pre=(*s[j].begin());
            if(cnt[pos][j])s[j].erase(s[j].find(cnt[pos][j]));
            cnt[pos][j]+=cntt;
            s[j].insert(cnt[pos][j]);
            if(s[j].size()==n){
                // puts("Carls");
                g*=do_main(j,(*s[j].begin())-pre);
            }
            g%=MOD;
        // puts("debug");
        }
        if(tmp!=1){
            int j=tmp,pre=0;
            if(s[j].size()==n)pre=(*s[j].begin());
            if(cnt[pos][j])s[j].erase(s[j].find(cnt[pos][j]));
            cnt[pos][j]++;
            s[j].insert(cnt[pos][j]);
            if(s[j].size()==n)g*=do_main(j,(*s[j].begin())-pre);    
        }
        g%=MOD;
        printf("%lld\n",g);
        // printf("debug:%d\n",s[5].size());
    }
    return 0;
}