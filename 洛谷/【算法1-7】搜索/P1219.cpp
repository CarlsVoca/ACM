#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=15;

bool l[maxn];
bool x1[maxn+maxn],x2[maxn+maxn];
int a[maxn];

int sum;
int n;

void print()
{
	sum++;
	if(sum<=3){
		for(int i=1;i<=n;i++){
			cout<<a[i];
			cout<<" ";
		}
		cout<<endl;
	}
}

void dfs(int i)
{
	for(int j=1;j<=n;j++){
		if(!l[j]&&!x1[i+j]&&!x2[i+n-j+2]){
		  l[j]=1;
		  x1[i+j]=1;
		  x2[i+n-j+2]=1;
		  a[i]=j;
		  if(i==n){
		  	print();
		  }
		  else dfs(i+1);
		  l[j]=0;
		  x1[i+j]=0;
		  x2[i+n-j+2]=0;
        }
	}
}


int main()
{
	cin>>n;
	dfs(1);
	cout<<sum<<endl;
	return 0;
}