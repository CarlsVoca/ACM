#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=15;

priority_queue< pii,vector<pii>,greater<pii> > pq[maxn];
map<int,int> cnt[maxn];

int id(char c){
    if(c=='A')return 1;
    else if(c>='2'&&c<='9')return c-'0';
    else if(c=='D')return 10;
    else if(c=='Q')return 11;
    else if(c=='J')return 12;
    return 13;
}

int n,k,t=0;
int pos;

void dw(int x,int y){
    pii tmp=pq[x].top();pq[x].pop();
    tmp.first--;
    if(tmp.first)pq[x].push(tmp);
}

void ps(int x,int y){
    vector<pii> g;g.clear();
    while(!pq[x].empty()){
        pii tmp=pq[x].top();pq[x].pop();
        if(tmp.second==y){
            tmp.first++;
            pq[x].push(tmp);
            rep(i,0,(int)g.size()-1LL)pq[x].push(g[i]);
            return;
        }
        g.push_back(tmp);
    }
    rep(i,0,(int)g.size()-1LL)pq[x].push(g[i]);
    pq[x].push(mp(1,y));
}

bool check(int x){
    if(k==x)return 0;
    if(pq[x].size()==1)return 1;
    return 0;
}

int ans=0;
bool judge(){
    int res=INF;
    rep(i,1,n){
        if(check(i)&&pq[i].top().second<res){
            ans=i;
            res=pq[i].top().second;
        }
    }
    if(res==INF)return 0;
    return 1;
}

int main(){
    scanf("%d%d",&n,&k); 
    pos=k;
    rep(i,1,n){
        string s;
        cin>>s;
        rep(j,0,3){
            cnt[i][id(s[j])]++;
        }
        for(auto p:cnt[i]){
            pq[i].push(mp(p.second,p.first));
        }
    }
    if(judge()){printf("%d\n",ans);return 0;}
    // int T=100;
    while(1){
        // printf("debug:%d\n",pos);
        if(pos==k){
            if(t==0){
                t=1;
                int tmp=pq[pos].top().second;
                dw(pos,tmp);
                ps(pos%n+1,tmp);
                if(judge()){
                    printf("%d\n",ans);
                    return 0;
                }
            }
            else{
                t=0;
                k=k%n+1;
                if(judge()){
                    printf("%d\n",ans);
                    return 0;
                }
            }
        }
        else{
            int tmp=pq[pos].top().second;
            dw(pos,tmp);
            ps(pos%n+1,tmp);
            if(judge()){
                printf("%d\n",ans);
                return 0;
            }
        }
        pos=pos%n+1;
    }
    return 0;
}