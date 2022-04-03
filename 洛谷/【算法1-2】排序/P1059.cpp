#include<cstdio> 
#include<iostream>
#include<cstring>
#include<set>

using namespace std;

set< int > s;

int a[1005];

int main()
{
	int n;
	int a,num=0;;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		s.insert(a);
	}
	int ans=s.size();
	cout<<ans<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();++it){
		cout<<*it<<" ";
	}
	return 0;
}
