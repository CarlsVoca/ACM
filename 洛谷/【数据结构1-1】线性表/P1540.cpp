#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

const int maxm=105;

string dic[maxm];
int now=0,n,m,ans=0;

bool find(const string ch)
{
	for(int i=1;i<=m;i++){
		if(dic[i]==ch)return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d",&m,&n);
	string ch;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(!find(ch)){
			ans++;
			now++;
			if(now>m)now=1;
			dic[now]=ch;
		}
	}
	printf("%d\n",ans);
	return 0;
}