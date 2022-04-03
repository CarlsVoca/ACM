#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int a[maxn],b[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x;
        scanf("%d%d",&n,&x);
        rep(i,1,n){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        bool flag=1;
        for(int i=n-x+1;i<=x;i++){
            if(a[i]!=b[i]){
                flag=0;
                break;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}