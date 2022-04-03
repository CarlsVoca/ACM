#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

char s[maxn][maxn];
int f[maxn*maxn];
int n,m;

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

int id(int x,int y){
    return (x-1)*m+y;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=0;i<=n*m;i++)f[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x<1||x>n||y<1||y>m||s[i][j]!=s[x][y])continue;
                int f1=find(id(i,j)),f2=find(id(x,y));
                if(f1==f2)continue;
                f[f1]=f2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i][1]=='O'){
            int f1=find(id(i,1)),f2=find(0);
            if(f1==f2)continue;
            f[f1]=f2;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i][m]=='O'){
            int f1=find(id(i,m)),f2=find(0);
            if(f1==f2)continue;
            f[f1]=f2;
        }
    }
    for(int i=1;i<=m;i++){
        if(s[1][i]=='O'){
            int f1=find(id(1,i)),f2=find(0);
            if(f1==f2)continue;
            f[f1]=f2;
        }
    }
    for(int i=1;i<=m;i++){
        if(s[n][i]=='O'){
            int f1=find(id(n,i)),f2=find(0);
            if(f1==f2)continue;
            f[f1]=f2;
        }
    }
    int ans=0;
    int S=find(0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='O'&&find(id(i,j))!=S){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}