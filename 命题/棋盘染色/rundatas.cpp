#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

const int maxn=1000;

int random(int MIN,int MAX){
	return rand()%(MAX-MIN+1)+MIN;
}

int A[maxn*maxn];

int main()
{
	freopen("3.in","w",stdout);
	srand(time(0));
	int n=random(1,maxn),m=random(1,1);
	int maxa=1000000;
	int a=random(1,maxa),b=random(1,maxa),c=random(1,maxa),d=random(1,maxa),p=random(1,maxa);
	printf("%d %d\n",n,m);
	A[0]=a;
	rep(i,1,n*m)A[i]=(1LL*A[i-1]*A[i-1]*b+1LL*A[i-1]*c+d)%p;
    rep(i,1,n){
        rep(j,1,m){
            printf("%lld ",A[m*(i-1)+j]);
        }
        putchar('\n');
    }
	return 0;
}