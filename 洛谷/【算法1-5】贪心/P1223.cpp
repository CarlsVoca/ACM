#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1005;

struct student{
	int time,num;
}a[maxn];

bool cmp(student a,student b)
{
	return a.time<b.time;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].time;
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	int now=0;
	double sum=0;
	for(int i=1;i<=n;i++){
		sum+=now;
		cout<<a[i].num<<" ";
		now+=a[i].time;
	}
	cout<<endl;
	printf("%.2f",sum/n);
	return 0;
}