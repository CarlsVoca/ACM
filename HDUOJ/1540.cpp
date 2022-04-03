#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

int n,m;

namespace Binary_Indexed_Tree{
    int c[maxn];
    void Change(int x,int k){
        for(;x<=n;x+=x&-x)c[x]+=k;
    }
    int Query(int x){
        int res=0;
        for(;x;x-=x&-x)res+=c[x];
        return res;
    }
}
using namespace Binary_Indexed_Tree;

int main(){
    while(scanf("%d%d",&n,&m)==2){
        rep(i,1,n)c[i]=0;
        rep(i,1,n)Change(i,1);
        int last=0;
        rep(i,1,m){
            char c;
            int x;
            cin>>c;
            if(c=='D'){
                scanf("%d",&x);
                last=x;
                if(Query(x)-Query(x-1)==0)continue;
                Change(x,-1);
            }
            else if(c=='Q'){
                scanf("%d",&x);
                if(Query(x)-Query(x-1)==0){puts("0");continue;}
                int l=1,r=x,ll=x,rr=x;
                while(l<r){
                    int mid=l+r>>1;
                    if(Query(x)-Query(mid-1)==x-mid+1)r=mid;
                    else l=mid+1;
                }
                ll=l;
                l=x,r=n;
                while(l<r){
                    int mid=(l+r>>1)+1;
                    if(Query(mid)-Query(x-1)==mid-x+1)l=mid;
                    else r=mid-1;
                }
                rr=l;
                printf("%d\n",rr-ll+1);
            }
            else if(last)Change(last,1);
        }
    }
    return 0;
}