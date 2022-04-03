#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=105;

int a[maxn],cnt[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<n;i++){
            while(k&&a[i]){
                a[i]--;
                a[n]++;
                k--;
            }
        }
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        putchar('\n');
    }
    return 0;
}