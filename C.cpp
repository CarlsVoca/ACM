#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			scanf("%d",&a[j]);
		}
		sort(a+1,a+m+1);//对他给出的数列进行排序，方便我们后面判断
		bool flag=1;//用来记录是否是等差数列，初始我们先假定他是等差数列，所以赋值为1
		for(int j=3;j<=m;j++){
			if( a[j]-a[j-1] != a[j-1]-a[j-2] ){//这个数和前一个数的差值 不等于 前一个数和前前一个数的差值，这个数列中就出现了不同的差值，他不是等差数列
				flag=0;//将flag变为0，表示不是等差数列
				break;//判断是否是等差数列的任务完成，退出循环
			}
		}
		if(flag)puts("yes");
		else puts("no");
	}
	return 0;
}