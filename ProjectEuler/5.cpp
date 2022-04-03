#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL Gcd(LL a,LL b){
	return b?Gcd(b,a%b):a;
}

LL Lcm(LL a,LL b){
	return a*b/Gcd(a,b);
}

int main()
{
	freopen("answer.txt","w",stdout);
	LL ans=1;
	for(int i=11;i<=20;i++){
		ans=Lcm(ans,i);
	}
	cout<<ans<<endl;
	return 0;
}
