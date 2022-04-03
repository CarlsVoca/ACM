#include<cstdio>
#include<iostream>

using namespace std;

const int maxn=5005;

int f[maxn];

inline void pre(int n)
{
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}

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
	int n,m,p;
	cin>>n>>m>>p;
	pre(n);
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		merge(x,y);
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		if(find(x)==find(y))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}