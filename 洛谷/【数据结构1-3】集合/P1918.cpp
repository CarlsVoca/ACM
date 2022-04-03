#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

map<int,int> mp;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        mp[x]=i;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int m;
        scanf("%d",&m);
        printf("%d\n",mp[m]);
    }
    return 0;
}