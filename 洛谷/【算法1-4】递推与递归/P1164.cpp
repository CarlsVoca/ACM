#include<cstdio>
using namespace std;
int f[10001],v[10001];
int m,n;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
      scanf("%d",&v[i]);
    f[0]=1;
    for(int i=1;i<=n;++i)
      for(int j=m;j>=v[i];--j)
        f[j]+=f[j-v[i]];
    printf("%d",f[m]);
    return 0;
}