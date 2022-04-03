#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn=5005;

struct player{
	int number,result;
}p[maxn];

bool cmp(player a,player b)
{
	if(a.result==b.result)return a.number<b.number;
	return a.result>b.result;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].number>>p[i].result;
	}
	sort(p+1,p+n+1,cmp);
	int ans=p[int(floor(m*1.5))].result;
	cout<<ans<<" ";
	int sum=0;
	for(int i=1;i<=n;i++){
		if(p[i].result<ans)break;
		else{
			sum++;
		}
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;i++){
		if(p[i].result<ans)break;
		else{
			cout<<p[i].number<<" "<<p[i].result<<endl;
		}
	}
	return 0;
} 


