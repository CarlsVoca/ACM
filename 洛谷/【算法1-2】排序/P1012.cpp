#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn=25;

bool cmp(string a,string b)
{
	return a+b>b+a?1:0;
}

int main()
{
	int n;
	string s[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
	  cout<<s[i];
	return 0;
}