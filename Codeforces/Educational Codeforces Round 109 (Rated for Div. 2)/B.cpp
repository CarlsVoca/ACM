#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=55;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        bool flag=1;
        rep(i,1,n)if(a[i]!=i){flag=0;break;}
        if(flag){
            puts("0");
            continue;
        }
        if(a[1]==1||a[n]==n){
            puts("1");
            continue;
        }
        if(a[1]==n&&a[n]==1){
            puts("3");
            continue;
        }
        puts("2");
    }
    return 0;
}