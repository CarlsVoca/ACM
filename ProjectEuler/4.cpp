#include<bits/stdc++.h>

using namespace std;

bool check(int x){
	int digit[10],len=0;
	while(x){
		digit[++len]=x%10;
		x/=10;
	}
	int l=1,r=len;
	while(l<r){
		if(digit[l]!=digit[r])return 0;
		l++,r--;
	}
	return 1;
}

int main()
{
	freopen("answer.txt","w",stdout);
	int ans=0;
	for(int i=100;i<=999;i++)
		for(int j=i;j<999;j++){
			int x=i*j;
			if(check(x))ans=max(ans,x);
		}
	cout<<ans<<endl;
	return 0;
}
