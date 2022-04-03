#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

stack<LL> sta;
string s;

int main(){
	cin>>s;
	int n=s.length();
	LL tmp=0;
	for(int i=0;i<n;i++){
		if(s[i]=='@')break;
		else if(s[i]=='.'){
			sta.push(tmp);
			tmp=0;
		}
		else if(s[i]=='-'){
			int a=sta.top();sta.pop();
			int b=sta.top();sta.pop();
			sta.push(b-a);
		}
		else if(s[i]=='+'){
			int a=sta.top();sta.pop();
			int b=sta.top();sta.pop();
			sta.push(b+a);
		}
		else if(s[i]=='*'){
			int a=sta.top();sta.pop();
			int b=sta.top();sta.pop();
			sta.push(b*a);
		}
		else if(s[i]=='/'){
			int a=sta.top();sta.pop();
			int b=sta.top();sta.pop();
			sta.push(b/a);
		}
		else{
			tmp*=10;
			tmp+=s[i]-'0';
		}
	}
	printf("%lld\n",sta.top());
	return 0;
}