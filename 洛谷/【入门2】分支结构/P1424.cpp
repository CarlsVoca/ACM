#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    long x,n;
    long long s=0;
    cin>>x>>n;
    for(int i=0;i<=n-1;++i)
      if((x+i)%7!=0&&(x+i)%7!=6)
        s+=150+100;
    cout<<s;
    return 0;
}

