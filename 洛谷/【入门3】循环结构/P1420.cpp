#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=0,a[10002],coui=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]-a[i-1]==1)
		  coui++;
	    else
	    {
	    	ans=max(ans,coui);
	    	coui=1;
		}
	}
	printf("%d",ans);
	return 0;
}