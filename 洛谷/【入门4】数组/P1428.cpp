#include<cstdio>
#include<iostream>

using namespace std;

const int maxn=105;

int a[maxn],b[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      for(int j=1;j<=i;j++){
        if(a[i]>a[j])
         b[i]++;
      }
    }
    for(int i=1;i<=n;i++)
      printf("%d ",b[i]);
    system("pause");
    return 0;
}








