#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

const int maxn=100005;

int cnt[55];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,W,tot=0;
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d",&n,&W);
        rep(i,1,n){
            int w;
            scanf("%d",&w);
            cnt[(int)log2(w)]++;
            tot++;
        }
        int ans=0;
        while(tot){
            int rest=W;
            per(i,30,0){
                while(cnt[i]&&rest>=(1<<i)){
                    cnt[i]--;tot--;
                    rest-=(1<<i);
                }
            }
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}