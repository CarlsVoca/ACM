#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1000005;

struct Line{
    int l,r;
    bool  operator < (const Line& b)const{
        return r<b.r;
    }
}l[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&l[i].l,&l[i].r);
    sort(l+1,l+n+1);
    int top=0,ans=0;
    rep(i,1,n){
        if(l[i].l>=top){
            ans++;
            top=l[i].r;
        }
    }
    printf("%d\n",ans);
    return 0;
}