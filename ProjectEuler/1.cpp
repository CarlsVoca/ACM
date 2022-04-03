#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("answer.txt","w",stdout);
	int ans=0;
	for(int i=3;i<1000;i+=3){
		if(i%5)ans+=i;
	}
	for(int i=5;i<1000;i+=5){
		ans+=i;
	}
	cout<<ans;
}
