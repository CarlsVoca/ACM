#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	freopen("answer.txt","w",stdout);
	LL a=600851475143;
	LL n=sqrt(a);
	int ans=1;
	for(int i=2;i<=n;i++){
		while(a%i==0){
			ans=max(ans,i);
			a/=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
