#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=25;

set<pii> s[maxn];
int op[maxn*maxn],a[maxn][maxn],t[maxn][maxn];
int b[maxn],tt[maxn],c[maxn];

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    rep(i,1,n*m)scanf("%d",&op[i]);
    rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
    rep(i,1,n)rep(j,1,m)scanf("%d",&t[i][j]);
    rep(i,1,n*m){
        bool flag=0;
        b[op[i]]++;
        int tmp1=a[op[i]][b[op[i]]],tmp2=t[op[i]][b[op[i]]];
        for(set<pii>::iterator it=s[tmp1].begin();it!=s[tmp1].end();++it){
            pii tmp=(*it);
            // printf("debug:(%d,%d)\n",tmp.first,tmp.second);
            if(tmp.second-max(c[op[i]]+1,tmp.first)+1>=tmp2){
                flag=1;
                s[tmp1].erase(it);
                if(tmp.first>c[op[i]]){
                    if(tmp.second-tmp.first+1>tmp2){
                        s[tmp1].insert(mp(tmp.first+tmp2,tmp.second));
                    }
                    c[op[i]]=max(c[op[i]],tmp.first+tmp2-1);
                    break;
                }
                else{
                    s[tmp1].insert(mp(tmp.first,c[op[i]]));
                    if(tmp.second-c[op[i]]>tmp2){
                        s[tmp1].insert(mp(c[op[i]]+tmp2+1,tmp.second));
                    }
                    c[op[i]]=max(c[op[i]],c[op[i]]+tmp2);
                    break;    
                }
            }
        }
        if(!flag){
            if(c[op[i]]>tt[tmp1]){
                s[tmp1].insert(mp(tt[tmp1]+1,c[op[i]]));
                c[op[i]]=tt[tmp1]=c[op[i]]+tmp2;
            }
            else{
                c[op[i]]=tt[tmp1]=tt[tmp1]+tmp2;
            }
        }
        // rep(j,1,n)printf("c[%d]=%d ",j,c[j]);
        // rep(j,1,m)printf("tt[%d]=%d ",j,tt[j]);
        // putchar('\n');
    }
    int ans=0;
    rep(i,1,m)ans=max(ans,tt[i]);
    printf("%d\n",ans);
    return 0;
}