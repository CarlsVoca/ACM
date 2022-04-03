#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=200005;

int cnt[maxn];
struct Data{
    int a,id;
    bool operator < (const Data &d)const{
        return cnt[a]==cnt[d.a]?a<d.a:cnt[a]<cnt[d.a];
    }
}d[maxn];

int ans[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n)ans[i]=cnt[i]=0;
        rep(i,1,n){
            scanf("%d",&d[i].a);
            d[i].id=i;
            cnt[d[i].a]++;
        }
        sort(d+1,d+n+1);
        int res=0;
        int col=1,pre=1,st=n+1;
        rep(i,1,n){
            if(cnt[d[i].a]>=k){st=i;break;}
            if(col==1)pre=i;
            ans[d[i].id]=col;res++;
            col++;
            if(col==k+1)col=1;
        }
        if(col!=1){
            rep(i,pre,st-1)ans[d[i].id]=0,res--;
        }
        if(st!=n+1){
            while(st<=n){
                int t=1;
                while(t<=k){
                    ans[d[st].id]=t;res++;
                    t++;
                    st++;
                }
                while(st<=n&&d[st].a==d[st-1].a){
                    ans[d[st].id]=0;
                    st++;
                }
            }
        }
        rep(i,1,n)printf("%d ",ans[i]);
        putchar('\n');
    }
    return 0;
}