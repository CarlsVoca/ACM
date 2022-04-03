#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    int res=1,MAX=1;
    rep(i,2,n){
        if(a[i]>a[i-1])res++;
        else{
            MAX=max(res,MAX);
            res=1;
        }
    }
    MAX=max(res,MAX);
    res=1;
    rep(i,2,n){
        if(a[i]<a[i-1])res++;
        else{
            MAX=max(res,MAX);
            res=1;
        }
    }
    MAX=max(res,MAX);
    res=1;
    int cnt[2]={0},ed[2];
    rep(i,2,n){
        if(a[i]>a[i-1])res++;
        else{
            if(res==MAX)cnt[0]++,ed[0]=i-1;
            res=1;
        }
    }
    if(res==MAX)cnt[0]++,ed[0]=n;
    res=1;
    rep(i,2,n){
        if(a[i]<a[i-1])res++;
        else{
            if(res==MAX)cnt[1]++,ed[1]=i-1;
            res=1;
        }
    }
    if(res==MAX)cnt[1]++,ed[1]=n;
    res=1;
    if(cnt[0]==1&&cnt[1]==1&&ed[0]==ed[1]-MAX+1){
        if(MAX&1)puts("1");
        else puts("0");
    }
    else puts("0");
    // printf("debug:%d %d %d %d %d\n",MAX,cnt[0],cnt[1],ed[0],ed[1]);
    return 0;
}