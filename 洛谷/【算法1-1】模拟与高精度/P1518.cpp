#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> pII;

const int INF=0x3f3f3f3f;
const int maxn=11;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

char s[maxn][maxn];
map< pair<pII,pII>,bool > vis;

int main(){
    int fx,fy,cx,cy;
    rep(i,0,9)scanf("%s",s[i]);
    rep(i,0,9)rep(j,0,9){
        if(s[i][j]=='F')fx=i,fy=j;
        else if(s[i][j]=='C')cx=i,cy=j;
    }
    int t1=0,t2=0,ans=0;
    vis[mp(mp(mp(fx,fy),mp(dx[t1],dy[t1])),mp(mp(cx,cy),mp(dx[t2],dy[t2])))]=1;
    while(1){
        ans++;
        if(fx+dx[t1]<0||fx+dx[t1]>9||fy+dy[t1]<0||fy+dy[t1]>9||s[fx+dx[t1]][fy+dy[t1]]=='*')t1=(t1+1)%4;
        else{fx+=dx[t1];fy+=dy[t1];}
        if(cx+dx[t2]<0||cx+dx[t2]>9||cy+dy[t2]<0||cy+dy[t2]>9||s[cx+dx[t2]][cy+dy[t2]]=='*')t2=(t2+1)%4;
        else{cx+=dx[t2];cy+=dy[t2];}
        // printf("debug %d:(%d,%d) %d (%d,%d) %d\n",ans,fx,fy,t1,cx,cy,t2);
        if(vis.count(mp(mp(mp(fx,fy),mp(dx[t1],dy[t1])),mp(mp(cx,cy),mp(dx[t2],dy[t2]))))){ans=0;break;}
        else vis[mp(mp(mp(fx,fy),mp(dx[t1],dy[t1])),mp(mp(cx,cy),mp(dx[t2],dy[t2])))]=1;
        if(fx==cx&&fy==cy)break;
    }
    printf("%d\n",ans);
    return 0;
}