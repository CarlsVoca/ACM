#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
int a[8][3],b[7];
using namespace std;
int main()
{int r,s=0;
for(int i=1;i<=7;++i)
  cin>>a[i][1]>>a[i][2];
for(int i=1;i<=7;++i)
  if(a[i][1]+a[i][2]>8)
    b[i]=a[i][1]+a[i][2];
for(int i=1;i<=7;++i)
  if(b[i]>s)
    {r=i;
    s=b[i];}
if(s==0)
  cout<<"0";
else
  cout<<r<<endl;

return 0;
  
    }