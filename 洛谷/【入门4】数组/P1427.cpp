#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
long long a[101];
using namespace std;
int main()
{
  int i=1;
  while(cin>>a[i],a[i]!=0)
    {
      i++;
    }
  for(int j=i-1;j>=1;j--)
    cout<<a[j]<<" ";
  return 0;      
}