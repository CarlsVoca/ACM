#include<bits/stdc++.h>

using namespace std;

const int maxn=30005;

int a[maxn];

int main(){
    int w,n;
    scanf("%d%d",&w,&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(l<=r){
        if(a[l]+a[r]<=w)l++,r--;
        else r--;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}