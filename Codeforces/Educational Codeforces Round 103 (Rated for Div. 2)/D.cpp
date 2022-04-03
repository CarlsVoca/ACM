#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=3e5+5;

bool vis[maxn];
int sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        vis[0]=vis[n]=0;
        rep(i,1,n-1){
            if(s[i-1]!=s[i])vis[i]=1;
            else vis[i]=0;
        }
        rep(i,1,n)sum[i]=sum[i-1]+(int)vis[i];
        rep(i,0,n){
            if(i==0){
                if(s[0]=='L'){
                    printf("1 ");
                    continue;
                }
                else{
                    int l=i+1,r=n;
                    while(l<r){
                        int mid=l+r>>1;
                        if(sum[mid]-sum[i]==mid-i)l=mid+1;
                        else r=mid;
                    }
                    printf("%d\n",l-i+1);
                }
            }
            else if(i==n){
                if(s[n-1]=='R'){
                    printf("1 ");
                    continue;
                }
                else{
                    int l=0,r=i-1;
                    while(l<r){
                        int mid=(l+r>>1)+1;
                        if(sum[i-1]-(mid==0?0:sum[mid-1])==i-1-mid+1)r=mid-1;
                        else l=mid;
                    }
                    printf("%d ",i-l+1);    
                }
            }
            else{
                int res=0;
                if(s[i-1]=='L'){
                    int l=0,r=i-1;
                    while(l<r){
                        int mid=(l+r>>1)+1;
                        if(sum[i-1]-(mid==0?0:sum[mid-1])==i-1-mid+1)r=mid-1;
                        else l=mid;
                    }
                    // printf("debug:i=%d l=%d\n",i,l);
                    res+=i-l;
                }
                if(s[i]=='R'){
                    int l=i+1,r=n;
                    while(l<r){
                        int mid=l+r>>1;
                        if(sum[mid]-sum[i]==mid-i)l=mid+1;
                        else r=mid;
                    }
                    // printf("debug:i=%d r=%d\n",i,l);
                    res+=l-i;
                }
                printf("%d ",res+1);
            }
        }
        putchar('\n');
    }
    return 0;
}