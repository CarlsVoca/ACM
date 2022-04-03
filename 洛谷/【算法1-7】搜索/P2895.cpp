#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
const int maxm=50005;
const int maxn=305;

struct Data{
    int x,y,t;
};

int h[maxn][maxn],t[maxm],x[maxm],y[maxm];
bool vis[maxn][maxn];

int main(){
    int m;
    scanf("%d",&m);
    rep(i,1,m)scanf("%d%d%d",&x[i],&y[i],&t[i]);
    memset(h,0x3f,sizeof(h));
    rep(i,1,m){
        h[x[i]][y[i]]=min(h[x[i]][y[i]],t[i]);
        rep(j,0,3){
            int xx=x[i]+dx[j],yy=y[i]+dy[j];
            if(xx>=0&&yy>=0)h[xx][yy]=min(h[xx][yy],t[i]);
        }
    }
    queue<Data> q;
    q.push((Data){0,0,0});
    vis[0][0]=1;
    while(!q.empty()){
        Data tmp=q.front();q.pop();
        if(h[tmp.x][tmp.y]==INF){
            printf("%d\n",tmp.t);
            return 0;
        }
        rep(j,0,3){
            int xx=tmp.x+dx[j],yy=tmp.y+dy[j];
            if(xx>=0&&yy>=0&&h[xx][yy]>tmp.t+1&&!vis[xx][yy]){
                q.push((Data){xx,yy,tmp.t+1});
                vis[xx][yy]=1;
            }
        }
    }
    puts("-1");
    return 0;
}