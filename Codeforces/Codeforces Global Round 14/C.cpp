#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int maxn=100005;
const int INF=0x7fffffff;

struct Data{
    int h,id;
    bool operator < (const Data& d)const{
        return h<d.h;
    }
}d[maxn];
int ans[maxn];
priority_queue< pii,vector<pii>,greater<pii> > q;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        while(!q.empty())q.pop();
        int n,m,x;
        scanf("%d%d%d",&n,&m,&x);
        rep(i,1,m)q.push(pii(0,i));
        rep(i,1,n)scanf("%d",&d[i].h),d[i].id=i;
        sort(d+1,d+n+1);
        per(i,n,1){
            pii tmp=q.top();q.pop();
            tmp.first+=d[i].h;ans[d[i].id]=tmp.second;
            q.push(tmp);
        }
        int MAX=-INF,MIN=INF;
        while(!q.empty()){
            pii tmp=q.top();q.pop();
            MAX=max(MAX,tmp.first);
            MIN=min(MIN,tmp.first);
        }
        if(MAX-MIN<=x){
            puts("YES");
            rep(i,1,n)printf("%d ",ans[i]);
            putchar('\n');
        }
        else puts("NO");
    }
    return 0;
}