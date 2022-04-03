#include<bits/stdc++.h>

using namespace std;

const int maxn=305;
const double INF=1e20;

struct Point{
	double x,y;
    bool operator < (const Point p)const{
        return x<p.x;
    }
}p[maxn];

typedef Point Vector;

Vector operator - (Point a,Point b){
	return (Vector){a.x-b.x,a.y-b.y};
}

inline double cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}

int n;

namespace Binary_Answer{
	const double eps1=1e-5;
	inline bool check(Point ans){
		for(int i=2;i<=n;i++){
			if(cross(p[i-1]-ans,p[i]-ans)<0)return 0;
		}
		return 1;
	}
	inline double get_base(double x){
		int i=lower_bound(p+1,p+n,Point{x,0})-p;
		return (x-p[i-1].x)*(p[i].y-p[i-1].y)/(p[i].x-p[i-1].x)+p[i-1].y;
	}
	inline double do_main(double x){
		double l=0,r=INF;
		double base=get_base(x);
		while(r-l>eps1){
			double mid=(l+r)/2;
			if(check((Point){x,base+mid}))r=mid;
			else l=mid;
		}
		return l;
	}
}

namespace Simulate_Anneal{
	const double eps2=1e-5;
	inline bool accept(double delta,double temper){
		if(delta>=0)return 1;
		return rand()<exp(delta/temper)*RAND_MAX;
	}
	double solve(){
		double t=(p[n].x-p[1].x)*2,del=0.99;
		double plan=p[(n+1)/2].x;
        double res=Binary_Answer::do_main(plan),tmp;
		while(t>eps2){
			double new_plan=plan+((double)rand()/RAND_MAX*2-1)*t;
			if(new_plan<p[1].x||new_plan>p[n].x)continue;
			if(accept(res-(tmp=Binary_Answer::do_main(new_plan)),t))plan=new_plan,res=tmp;
			t*=del;
		}
		return res;
	}
	double do_main(){
		srand(20010817);
		double res=INF;
		int T=1;
		while(T--){
			res=min(res,solve());
		}
		return res;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i].x);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i].y);
	printf("%.3lf\n",Simulate_Anneal::do_main());
	return 0;
}