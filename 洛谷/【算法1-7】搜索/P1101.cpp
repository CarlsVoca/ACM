#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;
const int dx[]={-1,-1,-1,0,1,1,1,0};
const int dy[]={-1,0,1,1,1,0,-1,-1};

char s[maxn][maxn];
bool vis[maxn][maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%s",s[i]+1);
    rep(i,1,n)
        rep(j,1,n){
            rep(k,0,7){
                if(i+dx[k]*6>n||i+dx[k]*6<1||j+dy[k]*6>n||j+dy[k]*6<1)continue;
                if(s[i][j]=='y'&&s[i+dx[k]][j+dy[k]]=='i'&&s[i+dx[k]*2][j+dy[k]*2]=='z'&&s[i+dx[k]*3][j+dy[k]*3]=='h'&&s[i+dx[k]*4][j+dy[k]*4]=='o'&&s[i+dx[k]*5][j+dy[k]*5]=='n'&&s[i+dx[k]*6][j+dy[k]*6]=='g'){
                    rep(l,0,6)vis[i+l*dx[k]][j+l*dy[k]]=1;
                }
            }
        }
    rep(i,1,n){
        rep(j,1,n){
            if(vis[i][j])putchar(s[i][j]);
            else putchar('*');
        }
        putchar('\n');
    }
    return 0;
}