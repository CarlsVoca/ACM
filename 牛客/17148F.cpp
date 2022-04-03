#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

char s[maxn][maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			if(s[i][j]=='#')x=j,y=i;
		}
	}
	int sx,sy;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]!='*')continue;
            int cnt1=0,cnt2=0;
			if(i!=1)cnt1+=(s[i-1][j]=='*');
			if(i!=n)cnt1+=(s[i+1][j]=='*');
			if(j!=1)cnt2+=(s[i][j-1]=='*');
			if(j!=m)cnt2+=(s[i][j+1]=='*');
			if(cnt1&&cnt2){sx=j,sy=i;break;}
		}
	}
	printf("%d %d\n",x-sx,sy-y);
	return 0;
}