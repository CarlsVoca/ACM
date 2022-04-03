#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

void do_main(string s1,string s2){
	if(!s1.size()||!s2.size())return;
	char ch=s2[0];
	int pos=s1.find(ch);
	do_main(s1.substr(0,pos),s2.substr(1,pos));
	do_main(s1.substr(pos+1),s2.substr(pos+1));
	printf("%c",ch);
}

int main(){
	string a,b;
	cin>>a>>b;
	do_main(a,b);
	return 0;
}