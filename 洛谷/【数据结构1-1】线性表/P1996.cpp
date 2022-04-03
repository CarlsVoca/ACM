#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

queue<int> q;

int main(){
	int cnt=0,n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)q.push(i);
	while(!q.empty()){
		cnt++;
		int tmp=q.front();q.pop();
		if(cnt%m==0){if(!q.empty())printf("%d ",tmp);else printf("%d\n",tmp);}
		else q.push(tmp);
	}
	return 0;
}