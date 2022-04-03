#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            ans+=i*100+j;
        }
    }
    printf("%d\n",ans);
    return 0;
}