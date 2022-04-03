#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

map<char,char> l,r;
map<char,bool> vis;

void dfs(char f){
	if(f=='*')return;
	printf("%c",f);
	dfs(l[f]);
	dfs(r[f]);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,self,lson,rson;i<=n;i++){
		char s[7];
		scanf("%s",s+1);
		l[s[1]]=s[2];r[s[1]]=s[3];
		vis[s[2]]=vis[s[3]]=1;
	}
	char root;
	for(map<char,char>::iterator it=l.begin();it!=l.end();++it){
		if(!vis.count(it->first)){root=(it->first);break;}
	}
	dfs(root);
	return 0;
}