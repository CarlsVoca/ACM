#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int t[maxn],k[maxn],cnt[maxn];
vector<int> v[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int l=1,tot=0;
    rep(i,1,n){
        scanf("%d%d",&t[i],&k[i]);
        while(t[i]-t[l]>=86400){
            rep(j,0,k[l]-1){
                cnt[v[l][j]]--;
                if(cnt[v[l][j]]==0)tot--;
            }
            l++;
        }
        rep(j,1,k[i]){
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
            if(cnt[x]==0)tot++;
            cnt[x]++;
        }
        printf("%d\n",tot);
    }
    return 0;
}