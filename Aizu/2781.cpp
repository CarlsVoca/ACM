#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=405;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

string ss[maxn],s[maxn];
int dis[maxn][maxn];
int h,w;

void bfs(int x,int y){
    queue<pii> q;
    q.push(make_pair(x,y));
    dis[x][y]=0;
    while(!q.empty()){
        pii tmp=q.front();q.pop();
        rep(i,0,3){
            int xx=tmp.first+dx[i],yy=tmp.second+dy[i];
            if(xx<0||xx>=h||yy<0||yy>=w||dis[xx][yy]!=INF||s[xx][yy]=='#')continue;
            else{
                q.push(make_pair(xx,yy));
                dis[xx][yy]=dis[tmp.first][tmp.second]+1;
            }
        }
    }
}

int main(){
    int sx,sy,ex,ey;
    scanf("%d%d",&h,&w);
    rep(i,0,h-1)cin>>ss[i];
    // rep(i,0,h-1)cout<<ss[i]<<endl;
    
    rep(i,0,h-1){
        int pos=0;
        while(pos<ss[i].length()){
            if(ss[i][pos]=='@'||ss[i][pos]=='%'||ss[i][pos]=='.'||ss[i][pos]=='#'||ss[i][pos]=='$')s[i]+=ss[i][pos];
            pos++;
        }
        // rep(j,0,w-1){
            // if(ss[i][pos]=='\\')pos++;
            // s[i][j]=ss[i][pos];
            // if(ss[i][pos]!='\\'){s[i][j]=ss[i][pos];pos++;}
            // else{s[i][j]='$';pos+=2;}
            // cout<<"ccc"<<s[i][j];
        // }
        // cout<<endl;
    }
    
    // rep(i,0,h-1)cout<<s[i]<<endl;
    /*
    rep(i,0,h-1){
        rep(j,0,w-1){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    */
    memset(dis,0x3f,sizeof(dis));
    rep(i,0,h-1)
        rep(j,0,w-1){
            if(s[i][j]=='@')sx=i,sy=j;
            else if(s[i][j]=='%')ex=i,ey=j;
        }
    // printf("debug:%d %d %d %d\n",sx,sy,ex,ey);
    bfs(ex,ey);
    int MIN=INF;
    rep(i,0,h-1){
        rep(j,0,w-1){
            if(s[i][j]=='$')MIN=min(MIN,dis[i][j]);
        }
    }
    /*
    rep(i,0,h-1){
        rep(j,0,w-1){
            cout<<dis[i][j];
        }
        cout<<endl;
    }
    */
    // printf("debug:%d %d\n",MIN,dis[ex][ey]);
    if(MIN>dis[sx][sy])puts("Yes");
    else puts("No");
    return 0;
}