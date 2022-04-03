#include<bits/stdc++.h>

using namespace std;

const int maxn=3005;
const int INF=0x7fffffff;

int a[maxn],sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        int ans=INF;
        for(int i=1;i<=n;i++){
            int last=i,x=0,res=i-1;
            for(int j=i+1;j<=n;j++){
                x+=a[j];
                if(x==sum[i]){
                    res+=j-last-1;
                    x=0;
                    last=j;
                }
            }
            if(last==n){
                ans=min(ans,res);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}