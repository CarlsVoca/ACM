#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int sum=0,MAX=-INF;
    rep(i,1,n)scanf("%1d",&a[i]),sum+=a[i],MAX=max(MAX,a[i]);
    if(MAX==0){
        printf("%d\n",n);
        return 0;
    }
    int ans=-1;
    rep(i,MAX,sum-1){
        int tmp=0;
        bool flag=0;
        int cnt=0;
        rep(j,1,n){
            if(tmp+a[j]>i){
                if(tmp!=i){
                    flag=1;
                    break;
                }
                else tmp=a[j],cnt++;
            }
            else tmp+=a[j];
        }
        if(flag)continue;
        if(tmp==i)ans=max(cnt+1,ans);
    }
    printf("%d\n",ans);
    return 0;
}