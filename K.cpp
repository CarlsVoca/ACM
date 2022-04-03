#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=1005;

LL a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%lld",&a[i]);
        }
        LL cnt=0;
        rep(i,1,n-2){
            rep(j,i+1,n-1){
                rep(k,j+1,n){
                    LL tmp=a[i]*a[j]*a[k];
                    LL sq=floor(sqrt((double)tmp));
                    if(sq*sq==tmp)cnt++;
                }
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}