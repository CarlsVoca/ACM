#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105;
char a[maxn][maxn];
int main()
{
    int r,c,k;
    scanf("%d%d%d",&r,&c,&k);
    scanf("%c",&a[0][0]);
    for(int i=1;i<=r;i++)
      for(int j=1;j<=c+1;j++)
      {
        scanf("%c",&a[i][j]);
      }
    /*for(int i=1;i<=r;i++)
      for(int j=1;j<=c+1;j++)
      {
        printf("%c",a[i][j]);
      }*/
    int ans=0;
    for(int i=1;i<=r;i++)
      for(int j=1;j+k-1<=c+1;j++)
      {
        bool vis=1;
        for(int l=j;l<=j+k-1;l++)
          if(a[i][l]!='.')
            vis=0;
        if(vis==1)
          ans++;
        //printf("%d %d\n",i,ans);
      }
    for(int j=1;j<=c;j++)
      for(int i=1;i+k-1<=r;i++)
      {
        bool vis=1;
        for(int l=i;l<=i+k-1;l++)
          if(a[l][j]!='.')
            vis=0;
        if(vis==1)
          ans++;
        //printf("%d %d\n",j,ans);
      }
    if(k==1)
	  ans/=2; 
    printf("%d\n",ans);
    return 0;
}
