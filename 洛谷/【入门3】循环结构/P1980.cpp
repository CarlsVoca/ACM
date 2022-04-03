#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int x,v,n,a,sum=0;
    cin>>x>>n;
    for(int i=1;i<=x;++i)
      {
        v=i;    
        while(i)
          {
          a=i%10;
          i=i/10;
          if(a==n)
            sum++;
          }
        i=v;
      }
    cout<<sum;
    return 0;            
}