#include<cstdio> 
#include<iostream>
#include<cstring>

using namespace std;

const int maxn=105;

int a[maxn];

int main()
{
	int n;
	cin>>n;
	for(int i=n;i>=0;i--){
      cin>>a[i];
	}
	bool flag=0;
	for(int i=n;i>=0;i--){
		if(!flag&&a[i]){
			if(a[i]<0){
			  cout<<"-";
			  a[i]=-a[i];
		    }
		    if(a[i]!=1||i==0)cout<<a[i];
			if(i==1)cout<<"x";
			else if(i!=0)cout<<"x^"<<i;
			flag=1;
			continue;
		}
		if(a[i]){
			if(a[i]>0)cout<<"+";
			else {
			  cout<<"-";
		      a[i]=-a[i];
			}
			if(a[i]!=1||i==0)cout<<a[i];
			if(i==1)cout<<"x";
			else if(i!=0)cout<<"x^"<<i;
		}
	}
	return 0;
}