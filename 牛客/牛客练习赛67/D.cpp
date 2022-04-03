#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn];

int main(){
    int ans=0;
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    while(a[n]==0)n--;
    if(n==0||n==1){printf("%d\n",n);return 0;}
    per(i,n,1){
        if(i==n){
            if(a[i]!=a[i-1]){
                ans++;
                a[i]=a[i-1];
            }
        }
        else if(i==1){
            if(a[i]!=a[i+1]){
                ans++;
                a[i]=a[i+1];
            }
        }
        else{
            if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
                ans++;
                a[i]=a[i-1];
            }
        }
    }
    while(a[n]==0)n--;
    if(n==0){printf("%d\n",ans);return 0;}
    int m=unique(a+1,a+n+1)-a-1;
    printf("%d\n",ans+m);
    return 0;
}