#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const double eps=1e-8;
const double inf=1e20;
const double pi=acos(-1.0);
int sgn(double x){
    if(fabs(x)<eps)return 0;
    // if(x==0)return 0;
    return x>0?1:-1;
}

struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x=_x;y=_y;}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("%.2f %.2f\n",x,y);
    }
    bool operator == (const Point &b)const{
        return sgn(x-b.x)==0&&sgn(y-b.y)==0;
    }
    Point operator + (const Point &b)const{
        return Point(x+b.x,y+b.y);
    }
    Point operator - (const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    Point operator * (const double &k)const{
        return Point(x*k,y*k);
    }
    Point operator / (const double &k)const{
        return Point(x/k,y/k);
    }
    double operator * (const Point &b)const{
        return x*b.x+y*b.y;
    }
    double operator ^ (const Point &b)const{
        return x*b.y-y*b.x;
    }
    double length(){
        return hypot(x,y);
    }
};
typedef Point Vector;

//a点绕o点逆时针旋转angle
Point rotate(Point a,Point o,double angle){
    Point v=a-o;
    double c=cos(angle),s=sin(angle);
    return Point(o.x+v.x*c-v.y*s,o.y+v.x*s+v.y*c);
}

struct Line{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e){s=_s;e=_e;}
    bool operator == (const Line &b)const{
        return s==b.s&&e==b.e;
    }
    //根据一个点和倾斜角angle确定直线 0<=angle<pi
    Line(Point p,double angle){
        s=p;
        if(sgn(angle-pi/2)==0)e=s+Point(0,1);
        else e=s+Point(1,tan(angle));
    }
    //ax+by+c=0
    Line(double a,double b,double c){
        if(sgn(a)==0)s=Point(0,-c/b),e=Point(1,-c/b);
        else if(sgn(b)==0)s=Point(-c/a,0);
        else s=Point(0,-c/b),e=Point(1,(-c-a/b));
    }
    void input(){
        s.input();e.input();
    }
    double length(){
        return Vector(e-s).length();
    }
    //返回直线倾角 0<=angle<pi
    double angle(){
        double k=atan2(e.y-s.y,e.x-s.x);
        if(sgn(k)<0)k+=pi;
        if(sgn(k-pi)==0)k-=pi;
        return k;
    }
};
typedef Line Segment;

//点和直线位置关系
//1 在左侧
//2 在右侧
//3 在直线上
int p_relation_l(Point p,Line l){
    int c=sgn((p-l.s)^(l.e-l.s));
    if(c<0)return 1;
    else if(c>0)return 2;
    else return 3;
}

//点和线段位置关系
//1 在线段上
//0 不在线段上
bool p_relation_s(Point p,Segment s){
    return sgn((p-s.s)^(s.e-s.s))==0&&sgn((p-s.s)*(p-s.e))<=0;
}

//两直线平行
bool parallel(Line a,Line b){
    return sgn((a.e-a.s)^(b.e-b.s))==0;
}

//两线段相交
//0 不相交
//1 非规范相交
//2 规范相交
int s_relation_s(Segment a,Segment b){
    int d1=sgn((a.e-a.s)^(b.s-a.s));
	int d2=sgn((a.e-a.s)^(b.e-a.s));
	int d3=sgn((b.e-b.s)^(a.s-b.s));
	int d4=sgn((b.e-b.s)^(a.e-b.s));
	if((d1^d2)==-2&&(d3^d4)==-2)return 2;
	return (d1==0&&sgn((b.s-a.s)*(b.s-a.e))<=0)||(d2==0 && sgn((b.e-a.s)*(b.e-a.e))<=0)||(d3==0&&sgn((a.s-b.s)*(a.s-b.e))<=0)||(d4==0&&sgn((a.e-b.s)*(a.e-b.e))<=0);
}

//直线和线段相交
//0 不相交
//1 非规范相交
//2 规范相交
int l_relation_s(Line a,Segment b){
	int d1=sgn((a.e-a.s)^(b.s-a.s));
	int d2=sgn((a.e-a.s)^(b.e-a.s));
	if((d1^d2)==-2)return 2;
	return (d1==0||d2==0);
}

//两直线关系
//0 平行
//1 重合
//2 相交
int l_relation_l(Line a,Line b){
	if(parallel(a,b))
		return p_relation_l(a.s,b)==3;
	return 2;
}

//求两直线交点
//保证两直线不平行或重合
Point cross_point(Line a,Line b){
	double a1=(b.e-b.s)^(a.s-b.s);
	double a2=(b.e-b.s)^(a.e-b.s);
	return Point((a.s.x*a2-a.e.x*a1)/(a2-a1),(a.s.y*a2-a.e.y*a1)/(a2-a1));
}

//点到直线的距离
double p_distance_l(Point p,Line l){
    return fabs((p-l.s)^(l.e-l.s))/l.length();
}

//点到线段距离
double p_distance_s(Point p,Segment s){
    if(sgn((p-s.s)*(s.e-s.s))<0 || sgn((p-s.e)*(s.s-s.e))<0)
		return min((p-s.s).length(),(p-s.e).length());
	return p_distance_l(p,s);
}

//线段到线段距离
//前提两直线不相交
double s_distance_s(Segment a,Segment b){
    return min(min(p_distance_s(b.s,a),p_distance_s(b.e,a)),min(p_distance_s(a.s,b),p_distance_s(a.e,b)));
}

//点在直线上的投影
Point p_projection_l(Point p,Line l){
	return l.s+(((l.e-l.s)*((l.e-l.s)*(p-l.s)))/((l.e-l.s).length()*(l.e-l.s).length()));
}

//点关于直线的对称点
Point symmetry(Point p,Line l){
	Point q=p_projection_l(p,l);
	return Point(2*q.x-p.x,2*q.y-p.y);
}

double a,b,c;
Point A,B,C,D;
double f(double x){
    return a*x*x+b*x+c;
}

bool judge1(){
    double y=f(B.x);
    if(sgn(y-B.y)>0&&sgn(D.y-y)>=0)return 1;
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&a,&b,&c);
        scanf("%lf%lf%lf%lf%lf",&A.x,&B.x,&A.y,&C.y,&D.y);
        B.y=A.y;C.x=D.x=B.x;
        if(sgn(f(A.x)-A.y)<=0)puts("NO");
        else{
            if(judge1()){
                // printf("debug");
                double newa=a;
                double newb=-2*a*(2*B.x+b/(2*a));
                double newc=a*(2*B.x+b/(2*a))*(2*B.x+b/(2*a))+(4*a*c-b*b)/(4*a);
                a=newa;b=newb;c=newc;
            }
            // printf("y1=%lf y2=%lf\n",f(A.x),f(B.x));
            if(sgn(f(A.x)-A.y)==0||sgn(f(B.x)-B.y)==0||sgn(f(A.x)-A.y)==sgn(f(B.x)-B.y))puts("No");
            else puts("Yes");
        }
    }
    return 0;
}