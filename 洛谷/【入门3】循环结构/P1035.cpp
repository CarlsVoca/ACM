#include<cstdio>
#include<iostream>

using namespace std;
int main()
{
    double sum=0,n;
    int k;
    scanf("%d",&k);
    for(n=1;;n++){
      sum+=1/n;
      if(sum>k)break;
    }
    printf("%d\n",int(n));
    system("pause");
    return 0;
}




