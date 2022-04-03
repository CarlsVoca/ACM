#include<iostream> 
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> >pq;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		pq.push(x);
	}
	int ans=0;
	for(int i=1;i<=n-1;i++){
		int x=pq.top();
		pq.pop();
		int y=pq.top();
		pq.pop();
		ans+=x+y;
		pq.push(x+y);
	}
	printf("%d\n",ans);
	return 0;
} 


