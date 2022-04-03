#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=30005;

int a[maxn],b[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        b[1]=a[1];a[1]=0;
        bool flag=1;
        rep(i,2,n){
           b[i]=min(b[i-1],a[i]-a[i-1]);
           if(b[i]<0){flag=0;break;}
           a[i]-=b[i];
        }
        // rep(i,1,n)printf("%d ",a[i]);
        // putchar('\n');
        per(i,n-1,1)if(a[i]>a[i+1])flag=0;
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}