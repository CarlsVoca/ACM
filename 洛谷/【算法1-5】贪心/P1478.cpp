#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=5005;

struct apple{
       int h,w;
}able[maxn];

bool cmp(apple a,apple b)
{
     return a.w<b.w;
}

int main()
{
    int ans=0,n,s,a,b,inh,inw,num=0;
    scanf("%d%d%d%d",&n,&s,&a,&b);
    for(int i=1;i<=n;i++){
      scanf("%d%d",&inh,&inw);
      if(inh<=b||(inh>=a&&inh<=a+b)){
        able[++num].h=inh;
        able[num].w=inw;
      }
    }
    sort(able+1,able+num+1,cmp);
    for(int i=1;i<=num;i++){
      s-=able[i].w;
      if(s>=0)ans++;
      else break;
    }
    printf("%d\n",ans);
    return 0;
}

