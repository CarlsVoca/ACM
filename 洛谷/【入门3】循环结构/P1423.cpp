#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double x,s=0;
    int n=0;
    cin>>x;
    while(s<=x)
      {  
         n++;
         s+=2*pow(0.98,n-1);
      }
    cout<<n;
    return 0;
}