#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

void do_main(string s1,string s2){
	if(!s1.size()||!s2.size())return;
	char ch=s2[s2.size()-1];
	printf("%c",ch);
	int pos=s1.find(ch);
	do_main(s1.substr(0,pos),s2.substr(0,pos));
	do_main(s1.substr(pos+1),s2.substr(pos,s2.size()-pos-1));
}

int main(){
	string a,b;
	cin>>a>>b;
	do_main(a,b);
	puts("");
	return 0;
}