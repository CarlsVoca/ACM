#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	int ans=1;
	for(int i=0;i<=a.length()-2;i++){
		if(b[b.find(a[i+1])+1]==a[i]){
			ans*=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
