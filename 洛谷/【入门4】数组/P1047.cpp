#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
int a[3][101],trees[10001];
using namespace std;
int main()
{
  int l,m,sum=0;
  cin>>l>>m;
  for(int i=0;i<=l;++i)
    trees[i]=1;
    for(int i=1;i<=m;++i)
      cin>>a[1][i]>>a[2][i];
    for(int i=1;i<=m;++i)
      for(int j=a[1][i];j<=a[2][i];j++)
        trees[j]=0;
    for(int i=0;i<=l;++i)
      if(trees[i]==1)
        sum++;
  cout<<sum;
  return 0;      
}