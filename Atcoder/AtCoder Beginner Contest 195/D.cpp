#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=55;

struct Data{
    int w,v;
    bool operator < (const Data & d)const{
        return v>d.v;
    }
}d[maxn];

int a[maxn];

int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n)scanf("%d%d",&d[i].w,&d[i].v);
    sort(d+1,d+n+1);
    rep(i,1,m)scanf("%d",&a[i]);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        multiset<int> s;s.clear();
        rep(i,1,l-1)s.insert(a[i]);
        rep(i,r+1,m)s.insert(a[i]);
        int res=0;
        rep(i,1,n){
            auto it=s.lower_bound(d[i].w);
            // printf("debug:%d\n",*it);
            if(it==s.end())continue;
            else{
                s.erase(it);
                res+=d[i].v;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}