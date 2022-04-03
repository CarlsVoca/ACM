#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=1000005;

namespace Sieve_of_Euler_ex{
	int nump=0,prime[maxn];
	bool is_prime[maxn];
	void do_main(){
		memset(is_prime,1,sizeof(is_prime));
		is_prime[1]=0;
		for(int i=2;i<maxn;i++){
			if(is_prime[i])prime[++nump]=i;
			for(int j=1;j<=nump&&prime[j]*i<maxn;j++){
				is_prime[i*prime[j]]=0;
				if(i%prime[j]==0)break;
			}
		}
	}
}

int cnt(LL x){
	int num=1;
	for(int i=1;i<=Sieve_of_Euler_ex::nump&&Sieve_of_Euler_ex::prime[i]<=x;i++){
		if(x%Sieve_of_Euler_ex::prime[i]==0){
			int tmp=0;
			while(x%Sieve_of_Euler_ex::prime[i]==0){
				x/=Sieve_of_Euler_ex::prime[i];
				tmp++;
			}
			num*=(tmp+1);
		}
	}
	return num;
}

int main()
{
	Sieve_of_Euler_ex::do_main();
	LL sum=0;
	for(int i=1;;i++){
		sum+=i;
		if(cnt(sum)>500)break;
	}
	cout<<sum<<endl;
	return 0;
}
