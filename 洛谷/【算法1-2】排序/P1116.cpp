#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,temp,cou=0;
int a[10005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++)
      for(int j=1;j<=n-i;j++)
      {
        if(a[j]>a[j+1])
        {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
          cou++;
        }
      }
    printf("%d",cou);
    return 0;
}