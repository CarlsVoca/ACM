#include<cstdio> 
#include<cstring> 
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=305;

struct student{
	int sum,yuwen,num;
	student(){
		sum=yuwen=num=0;
	}
}a[maxn];

bool cmp(student a,student b)
{
	if(a.sum!=b.sum)return a.sum<b.sum;
	else if(a.yuwen!=b.yuwen)return a.yuwen<b.yuwen;
	return a.num>b.num;
}

int main()
{
	int n;
	scanf("%d",&n);
	int yu,shu,yai;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&yu,&shu,&yai);
		a[i].yuwen=yu;
		a[i].num=i;
		a[i].sum=yu+shu+yai;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=n-4;i--){
		printf("%d %d\n",a[i].num,a[i].sum);
	}
	return 0;
}
