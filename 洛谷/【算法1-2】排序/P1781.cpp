#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=25;

struct node{
	int num;
	string sum;
}a[maxn];

bool cmp(node a,node b)
{
	if(a.sum.length()==b.sum.length())return a.sum>b.sum;
	return a.sum.length()>b.sum.length();
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum;
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1].num<<endl;
	for(int i=0;i<a[1].sum.length();i++){
		cout<<a[1].sum[i];
	}
	return 0;
}


