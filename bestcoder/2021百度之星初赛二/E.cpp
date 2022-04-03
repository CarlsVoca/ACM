#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int MOD=998244353;
const int maxn=1e5+5;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,cnt=0;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n){
            if(a[i]==i)cnt++;
        }
        if(cnt<=2)puts("Second");
        else puts("First");
    }
    return 0;
}