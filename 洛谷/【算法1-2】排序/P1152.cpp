#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int a[maxn];
bool vis[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	bool flag=1;
	for(int i=2;i<=n;i++){
		int tmp=abs(a[i]-a[i-1]);
		if(tmp>=1&&tmp<=n-1&&!vis[tmp])vis[tmp]=1;
		else{
			flag=0;
			break;
		}
	}
	if(flag)puts("Jolly");
	else puts("Not jolly");
	return 0;
}