#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn],n;
int pos[maxn],sum[maxn];

int main(){
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
        a[i]%=n;
    }
    rep(i,1,n){
        sum[i]=(sum[i-1]+a[i])%n;
        if(sum[i]==0){
            printf("%d\n",i);
            rep(j,1,i)printf("%d ",j);
            return 0;
        }
        if(pos[sum[i]]){
            printf("%d\n",i-pos[sum[i]]);
            rep(j,pos[sum[i]]+1,i)printf("%d ",j);
            return 0;
        }
        pos[sum[i]]=i;
    }
    return 0;
}