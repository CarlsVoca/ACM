#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=1005;

int f[maxn];

int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y)
{
	f[find(x)]=find(y);
}

int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		merge(x,y);
	}
	for(int i=1;i<=n;i++){
		find(i);
	}
	sort(f+1,f+n+1);
	int ans=0;
	for(int i=2;i<=n;i++){
		if(f[i]!=f[i-1])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
