#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int k;
    scanf("%d",&k);
    int v=1,ans=0;
    for(int pos=1;pos<=k;){
        for(int j=1;j<=v&&pos<=k;j++){
            pos++;
            ans+=v;
        }
        v++;
    }
    printf("%d\n",ans);
    return 0;
}