#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{int left=0,out;
double save=0;
for(int i=1;i<=12;i++)
  {cin>>out;
  if(out>left+300)
    {cout<<"-"<<i<<endl;
    return 0;}
  else
    {left=left+300-out;
     if(left>=100)
     {save+=left/100*100;
     left=left%100;
     }
     }}
printf("%g",save*1.2+left);
  return 0;
}