#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=2000005;

LL prime[maxn];
int nump=0;
bool is_prime[maxn];
LL ans=0;

void pre_prime(){
	memset(is_prime,1,sizeof(is_prime));
	is_prime[1]=0;
	for(int i=2;i<2000000;i++){
		if(is_prime[i])prime[++nump]=i,ans+=i;
		for(int j=1;j<=nump&&i*prime[j]<2000000;j++){
			is_prime[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
}

int main()
{
	freopen("answer.txt","w",stdout);
	pre_prime();
	cout<<ans<<endl;
	return 0;
}
