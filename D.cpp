#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
	double Ax1,Ax2,Ay1,Ay2;
	double Bx1,Bx2,By1,By2;
	scanf("%lf%lf%lf%lf",&Ax1,&Ay1,&Ax2,&Ay2);
	if(Ax2<Ax1)swap(Ax1,Ax2);
	if(Ay2<Ay1)swap(Ay1,Ay2);
	scanf("%lf%lf%lf%lf",&Bx1,&By1,&Bx2,&By2);
	if(Bx2<Bx1)swap(Bx1,Bx2);
	if(By2<By1)swap(By1,By2);
	double Cx1,Cx2,Cy1,Cy2;
	Cx1=max(Ax1,Bx1);
	Cy1=max(Ay1,By1);
	Cx2=min(Ax2,Bx2);
	Cy2=min(Ay2,By2);
	if(Cy2<Cy1||Cx2<Cx1)puts("0.00");
	else printf("%.2lf\n",(Cy2-Cy1)*(Cx2-Cx1));
	return 0;
}