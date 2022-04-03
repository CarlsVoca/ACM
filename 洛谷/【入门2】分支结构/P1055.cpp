#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
char a[14];
using namespace std;
int main()
{
    int b=1,sum=0;
    for(int i=1;i<=13;++i)
      {scanf("%c",&a[i]);
      if(a[i]!='-'&&i!=13)
        {sum+=(a[i]-'0')*b;
        b++;}}
    sum%=11;
    char v=a[13];
    a[13]=sum==10?'X':sum+'0';
    if(v==a[13])
      cout<<"Right";
    else
      for(int i=1;i<=13;++i)
        cout<<a[i];
    return 0;
      
    

}