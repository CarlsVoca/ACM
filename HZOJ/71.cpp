#include<bits/stdc++.h>

using namespace std;

const int maxn=10005;

int f[maxn];

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)f[find(b)]=find(c);
        else find(b)==find(c)?puts("Yes"):puts("No");
    }
    return 0;
}