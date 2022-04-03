#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=205;

int a[maxn],b[maxn];
int s[10][10];

void pre()
{
	s[1][3]=1;
	s[1][4]=1;
	s[2][4]=1;
	s[3][5]=1;
	s[4][5]=1;
	s[3][1]=-1;
	s[4][1]=-1;
	s[4][2]=-1;
	s[5][3]=-1;
	s[5][4]=-1;
	s[1][2]=-1;
	s[2][3]=-1;
	s[3][4]=-1;
	s[1][5]=-1;
	s[2][5]=-1;
	s[2][1]=1;
	s[3][2]=1;
	s[4][3]=1;
	s[5][1]=1;
	s[5][2]=1;
}

int main()
{
	pre();
	int n,na,nb;
	int ansa=0,ansb=0;
	cin>>n>>na>>nb;
	for(int i=1;i<=na;i++){
		cin>>a[i];
		a[i]++;
	}
	for(int i=1;i<=nb;i++){
		cin>>b[i];
		b[i]++;
	}
	for(int i=1;i<=n;i++){
		if(s[a[(i-1)%na+1]][b[(i-1)%nb+1]]==1)ansa++;
		if(s[a[(i-1)%na+1]][b[(i-1)%nb+1]]==-1)ansb++;
	}
	cout<<ansa<<" "<<ansb<<endl;
	return 0;
}