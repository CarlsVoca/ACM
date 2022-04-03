#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn],b[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n)b[i]=a[i];
        rep(i,2,n){
            if(b[i]==a[i-1]||b[i]==b[i-1])b[i]++;
        }
        int cnt=1;
        rep(i,2,n)if(b[i]!=b[i-1])cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}