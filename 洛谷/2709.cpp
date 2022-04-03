#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=50005;

struct Query{
    int l,r,id;
}q[maxn];

int a[maxn],cnt[maxn],ans[maxn];

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,m)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    int bsz=sqrt(n);
    sort(q+1,q+m+1,[&bsz](Query a,Query b){
        return a.l/bsz==b.l/bsz?a.r<b.r:a.l/bsz<b.l/bsz;
    });
    int l=1,r=0,res=0;
    rep(i,1,m){
        while(r<q[i].r){
            r++;
            res-=cnt[a[r]]*cnt[a[r]];
            cnt[a[r]]++;
            res+=cnt[a[r]]*cnt[a[r]];
        }
        while(r>q[i].r){
            res-=cnt[a[r]]*cnt[a[r]];
            cnt[a[r]]--;
            res+=cnt[a[r]]*cnt[a[r]];
            r--;
        }
        while(l<q[i].l){
            res-=cnt[a[l]]*cnt[a[l]];
            cnt[a[l]]--;
            res+=cnt[a[l]]*cnt[a[l]];
            l++;
        }
        while(l>q[i].l){
            l--;
            res-=cnt[a[l]]*cnt[a[l]];
            cnt[a[l]]++;
            res+=cnt[a[l]]*cnt[a[l]];
        }
        ans[q[i].id]=res;
    }
    rep(i,1,m)printf("%d\n",ans[i]);
    return 0;
}