#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int a[maxn],b[maxn],cnt1[maxn],cnt2[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int A,B,k;
        scanf("%d%d%d",&A,&B,&k);
        rep(i,1,A)cnt1[i]=0;
        rep(i,1,B)cnt2[i]=0;
        rep(i,1,k)scanf("%d",&a[i]),cnt1[a[i]]++;
        rep(i,1,k)scanf("%d",&b[i]),cnt2[b[i]]++;
        LL ans=0;
        rep(i,1,k){
            ans+=k-cnt1[a[i]]-cnt2[b[i]]+1;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}