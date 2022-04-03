#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

int st_min[maxn][20],st_max[maxn][20];
int h[maxn];

void Init(int n){
    rep(i,1,n)st_min[i][0]=st_max[i][0]=h[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++){
            st_max[i][j]=max(st_max[i][j-1],st_max[i+(1<<j-1)][j-1]);
            st_min[i][j]=min(st_min[i][j-1],st_min[i+(1<<j-1)][j-1]);
        }
}

int query_max(int l,int r){
    int k=log2(r-l+1);
    return max(st_max[l][k],st_max[r-(1<<k)+1][k]);
}
int query_min(int l,int r){
    int k=log2(r-l+1);
    return min(st_min[l][k],st_min[r-(1<<k)+1][k]);
}

int main(){
    int n,Q;
    scanf("%d%d",&n,&Q);
    rep(i,1,n)scanf("%d",&h[i]);
    Init(n);
    rep(i,1,Q){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query_max(l,r)-query_min(l,r));
    }
    return 0;
}