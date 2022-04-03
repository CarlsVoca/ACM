#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int cnt[maxn],a[maxn],b[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)cnt[i]=0;
        rep(i,1,n){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int tot=0;
        rep(i,1,n){if(cnt[i])b[++tot]=cnt[i];}
        sort(b+1,b+tot+1);
        int cntt=1;
        per(i,tot-1,1){
            if(b[i+1]==b[i])cntt++;
            else break;
        }
        // printf("Debug:%d %d %d\n",n,cntt,b[tot]);
        printf("%d\n",(n-cntt*b[tot])/(b[tot]-1)+cntt-1);
    }
    return 0;
}