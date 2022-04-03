#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=405;
const double eps=1e-9;

struct Point{
    double x,y;
    Point operator - (const Point & p)const{
        return Point{x-p.x,y-p.y};
    }
    Point operator + (const Point & p)const{
        return Point{x+p.x,y+p.y};
    }
    double operator * (const Point & p)const{
        return x*p.x+y*p.y;
    }
}p[maxn];

double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct Edge{
    int u,v;
    double w;
    int nxt;
}e[maxn*maxn];
int nume=0,last[maxn];

void add_edge(int u,int v,double w){
    e[++nume]=Edge{u,v,w,last[u]};
    last[u]=nume;
}

int n,m,A,B;

namespace Dijkstra{
	typedef pair<double,int> pii;
    double d[maxn];
	void do_main(int s){
		priority_queue< pii,vector<pii>,greater<pii> >q;
		rep(i,1,4*n)d[i]=INF;
		d[s]=0;
		q.push(pii(0,s));
		while(!q.empty()){
			pii now=q.top();q.pop();
			int u=now.second;
			if(d[u]<now.first)continue;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(d[u]+e[i].w<d[v]){
					d[v]=d[u]+e[i].w;
					q.push(pii(d[v],v));
				}
			}
		}
	}
}
using namespace Dijkstra;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        nume=0;
        memset(last,0,sizeof(last));
        scanf("%d%d%d%d",&n,&m,&A,&B);
        for(int i=1;i<=4*n;i+=4){
            int q;
            scanf("%lf%lf%lf%lf%lf%lf%d",&p[i].x,&p[i].y,&p[i+1].x,&p[i+1].y,&p[i+2].x,&p[i+2].y,&q);
            if(fabs((p[i]-p[i+1])*(p[i+1]-p[i+2]))<eps){
                p[i+3]=p[i+2]+p[i]-p[i+1];
            }
            else if(fabs((p[i+1]-p[i])*(p[i+2]-p[i]))<eps){
                p[i+3]=p[i+1]+p[i+2]-p[i];
            }
            else{
                p[i+3]=p[i+1]+p[i]-p[i+2];
            }
            add_edge(i,i+1,dis(p[i],p[i+1])*q);
            add_edge(i+1,i,dis(p[i],p[i+1])*q);
            add_edge(i,i+2,dis(p[i],p[i+2])*q);
            add_edge(i+2,i,dis(p[i],p[i+2])*q);
            add_edge(i,i+3,dis(p[i],p[i+3])*q);
            add_edge(i+3,i,dis(p[i],p[i+3])*q);
            add_edge(i+1,i+2,dis(p[i+1],p[i+2])*q);
            add_edge(i+2,i+1,dis(p[i+1],p[i+2])*q);
            add_edge(i+1,i+3,dis(p[i+1],p[i+3])*q);
            add_edge(i+3,i+1,dis(p[i+1],p[i+3])*q);
            add_edge(i+2,i+3,dis(p[i+2],p[i+3])*q);
            add_edge(i+3,i+2,dis(p[i+2],p[i+3])*q);
        }
        for(int i=1;i<=4*n;i++){
            for(int j=1;j<=4*n;j++){
                if((i-1)/4!=(j-1)/4){
                    add_edge(i,j,dis(p[i],p[j])*m);
                }
            }
        }
        double ans=INF;
        rep(i,(A-1)*4+1,(A-1)*4+4){
            rep(j,(B-1)*4+1,(B-1)*4+4){
                do_main(i);
                ans=min(ans,d[j]);
            }
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}