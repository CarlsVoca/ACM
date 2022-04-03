#include<cstdio>
#include<iostream>

using namespace std;

const int a[]={6,2,5,5,4,5,6,3,7,6};

int cou(int x)
{
	int ans=0;
	if(x==0)ans+=a[0];
	while(x){
		ans+=a[x%10];
		x/=10;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	n-=4;
	int ans=0;
	for(int i=0;i<=1111;i++)
	  for(int j=0;j<=1111;j++)
	    if(cou(i)+cou(j)+cou(i+j)==n)
	      ans++;
	cout<<ans;
	return 0;
}