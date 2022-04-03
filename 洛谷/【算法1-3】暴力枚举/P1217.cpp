#include<cstdio> 
#include<iostream>
#include<cstring>

using namespace std;

bool is_prime(int x)
{
	for(int i=2;i*i<=x;i++)
	  if(x%i==0)return 0;
	return 1;
}

void getlen(int n,int &len)
{
	len=0;
	while(n){
		len++;
		n/=10;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	int lenn;
	int lenm;
	getlen(n,lenn);
	getlen(m,lenm);
	if(lenm>=1&&lenn<=1){
		if(n<=5)cout<<5<<endl;
		if(n<=7)cout<<7<<endl;
	}
	if(n<=11&&m>=11)cout<<11<<endl;
	int f=0;
	if(lenm>=3&&lenn<=3){
		for(int i=1;i<=9;i+=2)
		  for(int j=0;j<=9;j++){
		  	f=i*100+j*10+i;
		  	if(f<n)continue;
		  	if(f>m)return 0;
		  	if(is_prime(f))cout<<f<<endl;
		  }
	}
	if(lenm>=5&&lenn<=5){
		for(int a=1;a<=9;a+=2)
		  for(int b=0;b<=9;b++)
		    for(int c=0;c<=9;c++){
		    	f=a*10000+b*1000+c*100+b*10+a;
		    	if(f<n)continue;
		    	if(f>m)return 0;
		    	if(is_prime(f))cout<<f<<endl;
			}
	}
	if(lenm>=7&&lenn<=7){
		for(int a=1;a<=9;a+=2)
		  for(int b=0;b<=9;b++)
		   for(int c=0;c<=9;c++)
		    for(int d=0;d<=9;d++){
		    	f=a*1000000+b*100000+c*10000+d*1000+c*100+b*10+a;
		    	if(f<n)continue;
		    	if(f>m)return 0;
		    	if(is_prime(f))cout<<f<<endl;
			}
	}
	return 0;
} 


