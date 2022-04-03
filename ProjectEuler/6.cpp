#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	freopen("answer.txt","w",stdout);
	LL sum1=0,sum2=0;
	for(int i=1;i<=100;i++)sum1+=i*i;
	sum2=5050*5050;
	cout<<sum2-sum1<<endl;
	return 0;
}
