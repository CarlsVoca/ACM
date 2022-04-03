#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5005;

int a[maxn];

int solve(int l,int r,int h){
    if(l>r)return 0;
    else if(l==r)return a[l]-h==0?0:1;
    int tmp=a[l]-h,pos=l;
    rep(i,l,r)if(a[i]-h<tmp){tmp=a[i]-h;pos=i;}
    return min(r-l+1,tmp+solve(l,pos-1,h+tmp)+solve(pos+1,r,h+tmp));
}

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    printf("%d\n",solve(1,n,0));
    return 0;
}