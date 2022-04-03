#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=110;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        a[n+1]=0;
        sort(a+1,a+n+1);
        int cnt=1;
        rep(i,2,n+1){
            if(a[i]==a[i-1])cnt++;
            else break;
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}