#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6+5;

int du[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		du[u]++;
		du[v]++;
	}
	for(int i=1;i<=n;i++)printf("%d ",du[i]);
	return 0;
}