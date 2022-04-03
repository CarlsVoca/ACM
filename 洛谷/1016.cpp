#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<double,double> pdd;

const int INF=0x3f3f3f3f;
const int maxn=8;
const int maxc=50005;

double dis[maxn],p[maxn];
deque<pdd> q;

int main(){
    double d1,c,d2;
    int n;
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p[0],&n);
    dis[n+1]=d1;dis[0]=0;
    rep(i,1,n)scanf("%lf%lf",&dis[i],&p[i]);
    double ans=p[0]*c;
    q.push_back(pdd(p[0],c));
    rep(i,1,n+1){
        if(dis[i]-dis[i-1]>c*d2){
            puts("No Solution");
            return 0;
        }
        double tmp=(dis[i]-dis[i-1])/d2;
        while(!q.empty()&&q.front().second<=tmp){
            tmp-=q.front().second;
            q.pop_front();
        }
        if(tmp>0)q.front().second-=tmp;
        if(i!=n+1){
            tmp=(dis[i]-dis[i-1])/d2;
            while(!q.empty()&&q.back().first>p[i]){
                tmp+=q.back().second;
                ans-=q.back().second*q.back().first;
                q.pop_back();
            }
            ans+=p[i]*tmp;
            q.push_back(pdd(p[i],tmp));
        }
    }
    while(!q.empty()){
        ans-=q.front().first*q.front().second;
        q.pop_front();
    }
    printf("%.2lf\n",ans);
    return 0;
}