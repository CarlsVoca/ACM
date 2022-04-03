#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn=20005;

int a[maxn];

int main()
{
	int n,b;
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=n;i>=1;i--){
		sum+=a[i];
		if(sum>=b){
		  cout<<n-i+1<<endl;
          return 0;
		}
	}
	return 0;
}
