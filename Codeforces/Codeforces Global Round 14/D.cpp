#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=200005;

int cnt[maxn][2];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,l,r;
        scanf("%d%d%d",&n,&l,&r);
        int tot0=0,tot1=0;
        rep(i,1,n)cnt[i][0]=cnt[i][1]=0;
        rep(i,1,l){
            int x;
            scanf("%d",&x);
            cnt[x][0]++;
            tot0++;
        }
        rep(i,l+1,n){
            int x;
            scanf("%d",&x);
            cnt[x][1]++;
            tot1++;
        }
        int ans=0,l0=0,l1=0;
        rep(i,1,n){
            int k=min(cnt[i][0],cnt[i][1]);
            cnt[i][0]-=k;
            cnt[i][1]-=k;
            l0+=cnt[i][0],l1+=cnt[i][1];
        }
        rep(i,1,n){
            while(cnt[i][0]>=2&&l0>l1){
                l0-=2;
                cnt[i][0]-=2;
                ans++;
            }
            while(cnt[i][1]>=2&&l0<l1){
                l1-=2;
                cnt[i][1]-=2;
                ans++;
            }
        }
        ans+=(l0+l1)/2+abs(l0-l1)/2;
        printf("%d\n",ans);
    }
    return 0;
}