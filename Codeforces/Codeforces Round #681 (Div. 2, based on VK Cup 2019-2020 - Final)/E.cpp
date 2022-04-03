#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

LL a[maxn],sum[maxn],fac[maxn];
int n,q;

bool vis[maxn];
int sub[maxn],num;

void solve(LL k){
    rep(i,1,num)vis[i]=0;
    rep(i,1,num){
        int tmp=k/fac[num-i];
        k%=fac[num-i];
        rep(j,1,num){
            if(tmp==0&&!vis[j]){
                a[n-num+i]=sub[j];
                vis[j]=1;
                break;
            }
            else if(!vis[j])tmp--;
        }
    }
}

LL query(int l,int r,LL k){
    solve(k);
    LL res=0;
    if(l<n-num+1&&r<n-num+1)return sum[r]-sum[l-1];
    else if(l<n-num+1){
        res+=sum[n-num]-sum[l-1];l=n-num+1;
        rep(i,l,r)res+=a[i];
        return res;
    }
    else{
        rep(i,l,r)res+=a[i];
        return res;
    }
}

int main(){
    LL tot=0;
    scanf("%d%d",&n,&q);
    rep(i,1,n)a[i]=i,sum[i]=sum[i-1]+a[i];
    num=min(n,14);
    rep(i,n-num+1,n)sub[i-(n-num+1)+1]=a[i];
    fac[0]=1;
    rep(i,1,14)fac[i]=fac[i-1]*i;
    while(q--){
        int op,l,r,x;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(l,r,tot));
        }
        else{
            scanf("%d",&x);
            tot+=x;
        }
    }
    return 0;
}