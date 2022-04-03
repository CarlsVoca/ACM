#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=10005;

LL prime[maxn];
int nump=0;
bool is_prime[10000010];

void pre_prime(){
	memset(is_prime,1,sizeof(is_prime));
	is_prime[1]=0;
	for(int i=2;nump<10001;i++){
		if(is_prime[i])prime[++nump]=i;
		for(int j=1;j<=nump&&i*prime[j]<=10000005;j++){
			is_prime[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
}

int main()
{
	freopen("answer.txt","w",stdout);
	pre_prime();
	cout<<prime[10001]<<endl;
}
