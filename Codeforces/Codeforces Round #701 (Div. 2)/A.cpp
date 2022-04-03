#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int cul(int a,int b){
    int res=0;
    while(a){
        res++;
        a/=b;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        int ans;
        if(b!=1)ans=cul(a,b);
        else ans=cul(a,b+1)+1;
        rep(i,1,100){
            ans=min(ans,i+cul(a,b+i));
        }
        printf("%d\n",ans);
    }
    return 0;
}