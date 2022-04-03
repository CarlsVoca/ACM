#include<bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;

set<int>s;
set<int>::iterator it;

int main()
{
	int n,x;
	scanf("%d",&n);
	scanf("%d",&x);
	s.insert(INF);s.insert(-INF);
	s.insert(x);
	int ans=x;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		it=s.lower_bound(x);
		ans+=min(x-*(--it),*it-x);
		s.insert(x);
	}
	printf("%d\n",ans);
	return 0;
}