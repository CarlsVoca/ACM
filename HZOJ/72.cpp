#include<bits/stdc++.h>

using namespace std;

const int maxn=10005;

int f[maxn],p[maxn];
//0-tie 1-win 2-loss

int find(int x){
    if(f[x]==x)return x;
    int tmp=f[x];
    f[x]=find(f[x]);
    p[x]=(p[x]+p[tmp])%3;
    return f[x];
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i,p[i]=0;
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            int fb=find(b),fc=find(c);
            if(fb==fc)continue;
            else{
                f[fb]=fc;
                p[fb]=1;
            }
        }
        else{
            int fb=find(b),fc=find(c);
            if(fb!=fc){puts("Unknown");continue;}
            int res=(p[b]+(3-p[c]))%3;
            if(res==0)puts("Tie");
            else if(res==1)puts("Win");
            else puts("Loss");
        }
    }
    return 0;
}