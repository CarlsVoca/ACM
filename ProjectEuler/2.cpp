#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=10005;

int fi[maxn];

int main()
{
	freopen("answer.txt","w",stdout);
	LL ans=0;
	fi[0]=fi[1]=1;
	for(int i=2;fi[i-1]+fi[i-2]<=4000000;i++){
		fi[i]=fi[i-1]+fi[i-2];
		if((fi[i]&1)==0)ans+=fi[i];
	}
	cout<<ans<<endl;
}
