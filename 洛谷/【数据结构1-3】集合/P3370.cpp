#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int base=131;

vector <string> HASH[maxn];

int f(string a)
{
	int ans=0;
	for(int i=0;i<a.length();i++){
		ans=(ans*base+a[i]-'0')%maxn;
	}
	return ans;
}

bool check(string s,int pos)
{
	for(int i=0;i<HASH[pos].size();i++){
		if(HASH[pos][i]==s)return 1;
	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	int h;
	string s;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>s;
		h=f(s);
		//cout<<i<<" "<<h<<endl;
		if(check(s,h)==1)continue;
		else HASH[h].push_back(s),ans++;
	}
	cout<<ans<<endl;
	return 0;
}

