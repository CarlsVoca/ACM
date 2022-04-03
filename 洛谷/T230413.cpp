#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int n,va,vb,x,y;

bool check(int x){
    int neednay=(n+x-1)/x;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&n,&va,&vb,&x,&y);
        int l=1,r=200000;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        if(!check(l))puts("-1");
        else printf("%d\n",l);
    }
    return 0;
}