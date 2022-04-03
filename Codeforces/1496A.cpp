#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

char s[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        int cnt=0;
        rep(i,1,n/2){
            if(s[i]==s[n-i+1])cnt++;
            else break;
        }
        if(cnt>=k&&n>2*k)puts("YES");
        else puts("NO");
    }
    return 0;
}