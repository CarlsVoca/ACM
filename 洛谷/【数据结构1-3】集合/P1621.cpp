#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

const int maxn=100005;

bool vis[maxn];
int prime[maxn],num;
int uset[maxn];

set<int>s;

void pre_prime(int n)
{
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(vis[i]==0){
			prime[++num]=i;
		}
		for(int j=1;j<=num&&prime[j]*i<=n;j++){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}

void makeSet(int start,int end)
{
	for(int i=start;i<=end;i++){
		uset[i]=i;
	}
}

inline int find(int x)
{
	if(uset[x]==x)return x;
	return uset[x]=find(uset[x]);
}

inline void unionSet(int x,int y)
{
	uset[find(x)]=find(y);
}

int main()
{
	int a,b,p;
	cin>>a>>b>>p;
	pre_prime(b);
	makeSet(a,b);
	int start;
	for(int i=1;i<=num;i++){
		if(prime[i]>=p){
			start=i;
			break;
		}
	}
	for(int i=start;i<=num;i++){
		bool flag=0;
		for(int j=1;j*prime[i]<=b;j++){
			if(j*prime[i]>=a){
				if(!flag){
					flag=1;
					continue;
				}
				else{
					unionSet(j*prime[i],(j-1)*prime[i]);
				}
			}
		}
	}
	int ans=0;
	for(int i=a;i<=b;i++){
		if(!s.count(find(i))){
			ans++;
			s.insert(find(i)); 
		}
	}
	cout<<ans<<endl;
	return 0;
}
