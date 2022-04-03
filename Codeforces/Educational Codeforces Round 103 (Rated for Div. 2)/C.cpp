#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn],b[maxn],c[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&c[i]);
        int x;
        scanf("%d",&x);
        rep(i,1,n-1)scanf("%d",&a[i]);
        scanf("%d",&x);
        rep(i,1,n-1)scanf("%d",&b[i]);
        a[n]=b[n]=1;
        LL ans=0,res=0,pre=max(a[1],b[1])-min(a[1],b[1])+2;
        rep(i,2,n){
            ans=max(ans,c[i]-1+pre);
            if(a[i]==b[i])pre=2;
            else pre=max(max(a[i],b[i])-min(a[i],b[i])+2ll,pre+min(a[i],b[i])-1+c[i]-max(a[i],b[i])+2);
        }
        /*
        rep(i,1,n){
            if(i==1){
                res=max(a[i],b[i])-min(a[i],b[i]);
                res+=2;
                continue;
            }
            // printf("debug:%lld\n",res);
            if(a[i]==b[i]){
                ans=max(ans,res+c[i]-1);
                res=0;
                res+=2;
            }
            else{
                ans=max(ans,res+c[i]-1);
                res+=min(a[i],b[i])-1+c[i]-max(a[i],b[i]);
                res+=2;
            }
            // printf("debug:%d %lld\n",i,res);
        }
        */
        printf("%lld\n",ans);
    }
    return 0;
}