#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
int a[10];
using namespace std;
int main()
{for(int i=0;i<10;i++)
  cin>>a[i];
int n,num=0;
cin>>n;
for(int i=0;i<10;i++)
  if(n+30>=a[i])
    num+=1;
cout<<num;
return 0;    
    }