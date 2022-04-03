#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<string,int> psi;

const int INF=0x3f3f3f3f;
const int maxn=7;

string a[maxn],b[maxn];
string A,B;

map<string,bool> vis;
queue<psi> q;

int main(){
    cin>>A>>B;
    
    // rep(i,1,3)cin>>a[i]>>b[i];

    int cnt=1;
    while(cin>>a[cnt]>>b[cnt])cnt++;
    q.push(mp(A,0));
    vis[A]=1;
    // cout<<"Debug:"<<A<<endl;
    while(!q.empty()){
        psi tmp=q.front();q.pop();
        // cout<<"Debug:"<<tmp.first<<" "<<tmp.second<<endl;
        if(tmp.first==B){
            printf("%d\n",tmp.second);
            return 0;
        }
        if(tmp.second==10)continue;
        rep(i,0,tmp.first.length()-1){
            rep(j,1,cnt-1){
                if(i+a[j].length()<=tmp.first.length()){
                    if(tmp.first.substr(i,a[j].length())==a[j]){
                        string res=tmp.first.substr(0,i)+b[j]+tmp.first.substr(i+a[j].length());
                        if(!vis.count(res)&&res.length()<=20){
                            q.push(mp(res,tmp.second+1));
                            vis[res]=1;
                        }
                    }
                }
            }
        }
    }
    puts("NO ANSWER!");
    return 0;
}