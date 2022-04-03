#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=12;

char a[1<<maxn][1<<maxn];
int n;

void print(int size,int x,int y){
	if(size==1){
		a[x][y]='/';a[x][y+1]='_';a[x][y+2]='_';
		a[x-1][y+1]='/';a[x-1][y+2]='\\';a[x][y+3]='\\';
		return;
	}
	print(size-1,x,y);
	print(size-1,x-(1<<size)/2,y+(1<<size)/2);
	print(size-1,x,y+(1<<size));
}

int main(){
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	print(n,1<<n,1);
	for(int i=1;i<=(1<<n);i++){
		for(int j=1;j<=(1<<(n+1));j++)
			putchar(a[i][j]?a[i][j]:' ');
		putchar('\n');
	}
	return 0;
}