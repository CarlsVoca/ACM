#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=15;
const double eps=1e-9;
const int INF=0x3f3f3f3f;

vector<int> vec[maxn];
int a[maxn],pos[maxn];
int n;

bool accept(double temper,double delta){
    if(delta>=0)return 1;
    else return rand()<=exp(delta/temper)*RAND_MAX;
}

int random(int MIN,int MAX){
    return rand()%(MAX-MIN+1)+MIN;
}

int solve(){
    int res=0;
    // a[1]=6,a[2]=5,a[3]=1,a[4]=4,a[5]=2,a[6]=3;
    // pos[1]=3,pos[2]=5,pos[3]=6,pos[4]=4,pos[5]=2,pos[6]=1;
    rep(i,1,n)a[i]=i,pos[i]=i;
    rep(i,1,n){
        rep(j,0,2){
            res+=abs(i-pos[vec[a[i]][j]]);
        }
    }
    // printf("%d\n",res);
    double t=100000,del=0.999;
    while(t>eps){
        int x=random(1,n),y=random(1,n-1);
        if(y>=x)y++;
        // int delta=0;
        int tmp=0;
        swap(pos[a[x]],pos[a[y]]);
        swap(a[x],a[y]);
        rep(i,1,n){
            rep(j,0,2){
                tmp+=abs(i-pos[vec[a[i]][j]]);
            }
        }
        // delta-=abs(x-pos[vec[a[x]][0]])+abs(x-pos[vec[a[x]][1]])+abs(x-pos[vec[a[x]][2]]);
        // delta-=abs(y-pos[vec[a[y]][0]])+abs(y-pos[vec[a[y]][1]])+abs(y-pos[vec[a[y]][2]]);
        // delta+=abs(y-pos[vec[a[x]][0]])+abs(y-pos[vec[a[x]][1]])+abs(y-pos[vec[a[x]][2]]);
        // delta+=abs(x-pos[vec[a[y]][0]])+abs(x-pos[vec[a[y]][1]])+abs(x-pos[vec[a[y]][2]]);
        // printf("x=%d y=%d delta=%d\n",x,y,delta);
        if(accept(t,res-tmp))res=tmp;
        else{
            swap(pos[a[x]],pos[a[y]]);
            swap(a[x],a[y]);
        }
        t*=del;
    }
    return res;
}

int main(){
    scanf("%d",&n);
    rep(i,1,n){
        rep(j,1,3){
            int x;
            scanf("%d",&x);
            vec[i].push_back(x);
        }
    }
    srand(20010817);
    int T=10;
    int ans=INF;
    while(T--){
        ans=min(ans,solve());
    }
    printf("%d\n",ans/2);
    return 0;
}