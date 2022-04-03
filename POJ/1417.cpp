#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=605;

struct Data{
    int f,p,id;
    bool operator < (const Data &b)const{
        return f==b.f?p<b.p:f<b.f;
    }
}d[maxn];

void Init(int n){
    rep(i,1,n)d[i].f=i,d[i].p=0,d[i].id=i;
}

int Find(int x){
    if(d[x].f==x)return x;
    int tmp=d[x].f;
    d[x].f=Find(tmp);
    d[x].p=d[x].p^d[tmp].p;
    return d[x].f;
}

int a[maxn][2],tot=0,id[maxn],b[maxn],dp[maxn][maxn],p[maxn][maxn];

int main(){
    int n,p1,p2;
    while(scanf("%d%d%d",&n,&p1,&p2)==3){
        if(n==0&&p1==0&&p2==0)break;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        tot=0;
        int m=p1+p2;
        Init(m);
        rep(i,1,n){
            int x,y;
            string s;
            cin>>x>>y>>s;
            int fx=Find(x),fy=Find(y);
            if(fx==fy)continue;
            d[fx].f=fy;
            if(s=="yes")d[fx].p=d[x].p^d[y].p;
            else d[fx].p=d[x].p^d[y].p^1;
        }
        rep(i,1,m)Find(i);
        sort(d+1,d+m+1);
        int cnt[2]={0,0};
//        printf("debug:tot=%d m=%d\n",tot,m);
        rep(i,1,m){
            cnt[d[i].p]++;
            id[i]=tot+1;
            if((d[i].f!=d[i+1].f)||(i==(m))){
                tot++;
//                printf("debug:i=%d tot=%d\n",i,tot);
//                printf("debug:cnt[0]=%d\n",cnt[0]);
                a[tot][0]=cnt[0];
                a[tot][1]=cnt[1];
                cnt[0]=cnt[1]=0;
            }
        }
//        printf("debug:%d\n",a[1][0]);
//        printf("debug:tot=%d m=%d\n",tot,m);
        dp[0][0]=1;
        rep(i,1,tot){
            rep(j,min(a[i][0],a[i][1]),m){
                if(j-a[i][0]>=0&&dp[i-1][j-a[i][0]]){
                    dp[i][j]+=dp[i-1][j-a[i][0]];
                    p[i][j]=0;
                }
                if(j-a[i][1]>=0&&dp[i-1][j-a[i][1]]){
                    dp[i][j]+=dp[i-1][j-a[i][1]];
                    p[i][j]=1;
                }
//                printf("debug:dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
        if(dp[tot][p1]!=1)puts("no");
        else{
            vector<int> ans;
            int j=p1;
            per(i,tot,1){
                b[i]=p[i][j];
                j-=a[i][p[i][j]];
            }
            rep(i,1,m){
                if(d[i].p==b[id[i]])ans.push_back(d[i].id);        
            }
            sort(ans.begin(),ans.end());
            rep(i,0,(int)ans.size()-1LL)printf("%d\n",ans[i]);
            puts("end");
        }
    }
    return 0;
}