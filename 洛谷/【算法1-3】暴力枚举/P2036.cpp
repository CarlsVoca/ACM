#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=11;

int a[maxn],b[maxn];
int n,ans=INF;

void dfs(int i,int mul,int sum,bool k){
    if(i==n+1){
        if(k)ans=min(ans,abs(mul-sum));
        return;
    }
    dfs(i+1,mul,sum,k|0);
    dfs(i+1,mul*a[i],sum+b[i],1);
}

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&a[i],&b[i]);
    dfs(1,1,0,0);
    printf("%d\n",ans);
    return 0;
}