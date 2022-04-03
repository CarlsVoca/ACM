#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=55;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        map<int,int> mp;
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]),mp[a[i]]++;
        int ans=0;
        rep(i,2,2*n){
            int res=0;
            rep(j,1,(i-1)/2){
                res+=min(mp[j],mp[i-j]);
            }
            if(i%2==0)res+=mp[i/2]/2;
            ans=max(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}