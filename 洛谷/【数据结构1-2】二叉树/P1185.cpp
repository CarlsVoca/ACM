#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=4005;

char s[maxn][maxn];
bool b[maxn];
int n,m;

void del(int x){
    if(x>=(1<<n)||b[x]==0)return;
    b[x]=0;
    del(x<<1);del(x<<1|1);
}

bool check(int dep){
    rep(i,1<<(dep-1),(1<<dep)-1)if(b[i])return 1;
    return 0;
}

int f(int x){return (x-1)/2*6+(x&1?1:5);}
pii Pos(int id){
    int x,y,xx,yy;
    rep(i,1,n)if(id>=(1<<i-1)&&id<=(1<<i)-1){
        x=i;
        y=id-(1<<i-1)+1;
    }
    yy=(f((y-1)*(1<<n-x)+1)+f(y*(1<<n-x)))/2;
    xx=(f(1)+f((1<<n-1)))/2-(f(1)+f(1<<n-x))/2+1;
    return mp(xx,yy);
}

void draw(int x){
    pii pos=Pos(x);
    s[pos.first][pos.second]='o';
    if(x==1)return;
    else if(x&1){
        pos.first--;pos.second--;
        while(s[pos.first][pos.second]!='o'){s[pos.first][pos.second]='\\';pos.first--;pos.second--;}
    }
    else{
        pos.first--;pos.second++;
        while(s[pos.first][pos.second]!='o'){s[pos.first][pos.second]='/';pos.first--;pos.second++;}    
    }
}

int main(){
    // freopen("1.txt","w",stdout);
    scanf("%d%d",&n,&m);
    rep(i,1,(1<<n)-1)b[i]=1;
    rep(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        x=(1<<x-1)+y-1;
        del(x);
    }
    // while(n&&!check(n))n--;
    if(n==0){return 0;}
    int szx=(f(1)+f((1<<n-1)))/2,szy=f((1<<n)-1);
    rep(i,1,szx)rep(j,1,szy)s[i][j]=' ';
    rep(i,1,(1<<n)-1)if(b[i])draw(i);
    rep(i,1,szx){
        rep(j,1,szy){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}