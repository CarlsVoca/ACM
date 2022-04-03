#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=25;

string a[maxn];
int used[maxn],ans,n;
int now=1;

void dfs(int k)
{
	ans=max(ans,now);
	for(int i=1;i<=n;i++){
		if(used[i]<2){
			for(int j=0;j<a[k].length();j++){
				if(a[i][0]==a[k][j]){
				  int l=0;
				  while(a[i][l]==a[k][l+j]&&l+j<a[k].length())l++;
				  if(l+j==a[k].length()){
					now+=a[i].length()-l;
					used[i]++;
					dfs(i);
					now-=a[i].length()-l;
					used[i]--;
				  }
			    }
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>a[0];
	dfs(0);
	cout<<ans;
	return 0;
}
