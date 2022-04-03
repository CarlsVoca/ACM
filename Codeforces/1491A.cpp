#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int cnt[2],a[maxn];

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    rep(i,1,n){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    rep(i,1,q){
        int t,x;
        scanf("%d%d",&t,&x);
        if(t==1){
            if(a[x]==0){
                cnt[0]--;
                cnt[1]++;
                a[x]=1;
            }
            else{
                cnt[1]--;
                cnt[0]++;
                a[x]=0;
            }
        }
        else{
            if(x<=cnt[1])puts("1");
            else puts("0");
        }
    }
    return 0;
}