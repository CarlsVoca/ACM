#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=25;

int a[maxn];
int n,k;
int ans;

bool is_prime(int x)
{
	if(x==1||x==0)return 0;
	else if(x==2)return 1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return 0;
	}
	return 1;
}

void cou(int sum,int now,int num)
{
	if(num==k){
		if(is_prime(sum)){
			ans++;
			return;
		}
		return;
	}
	for(int i=now+1;i<=n;i++){
		if(n-now>=k-num){
			cou(sum+a[i],i,num+1);
		}
	}
	return;
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cou(0,0,0);
	cout<<ans;
	return 0;
}