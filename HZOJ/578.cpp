#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

typedef pair<int,int> pii;

map<pii,bool> mp;

bool vis[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d",&p);
        for(int j=1;j<=p;j++){
            int x;
            scanf("%d",&x);
            mp[pii(i,x)]=1;
        }
    }
    int k;
    scanf("%d",&k);
    while(k--){
        int tp,q;
        scanf("%d%d",&tp,&q);
        if(tp==1){
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=q;i++){
                int x;
                scanf("%d",&x);
                for(int j=1;j<=m;j++){
                    if(!mp.count(pii(x,j)))vis[j]=1;
                }
            }
            bool flag=0;
            for(int i=1;i<=m;i++){
                if(!vis[i]){
                    if(flag)putchar(' ');
                    else flag=1;
                    printf("%d",i);
                }
            }
            putchar('\n');
        }
        else if(tp==0){
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=q;i++){
                int x;
                scanf("%d",&x);
                for(int j=1;j<=m;j++){
                    if(mp.count(pii(x,j)))vis[j]=1;
                }
            }
            bool flag=0;
            for(int i=1;i<=m;i++){
                if(!vis[i]){
                    if(flag)putchar(' ');
                    else flag=1;
                    printf("%d",i);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}