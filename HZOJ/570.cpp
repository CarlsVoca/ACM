#include<bits/stdc++.h>

using namespace std;

const int maxn=80005;
const int INF=0x7fffffff;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    stack<int> sta;sta.push(n+1);a[n+1]=INF;
    int ans=0;
    for(int i=n;i>=1;i--){
        while(a[sta.top()]<a[i]){
            sta.pop();
        }
        ans+=sta.top()-i-1;
        sta.push(i);
        // printf("debug:%d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}