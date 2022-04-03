#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	int a,b,c;
	bool flag=0;
	for(a=123;a<=333;a++){
		b=a*B/A;
		c=a*C/A;
		if(a/100+a/10%10+a%10+b/100+b/10%10+b%10+c/100+c/10%10+c%10==1+2+3+4+5+6+7+8+9&&(a/100)*(a/10%10)*(a%10)*(b/100)*(b/10%10)*(b%10)*(c/100)*(c/10%10)*(c%10)==1*2*3*4*5*6*7*8*9){
			flag=1;
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
	}
	if(!flag)cout<<"No!!!"<<endl;
	return 0;
}