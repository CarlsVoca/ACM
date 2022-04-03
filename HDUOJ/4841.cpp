#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=35005;

int l[maxn],r[maxn];
char ans[maxn];

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        rep(i,1,2*n)ans[i]=0;
        rep(i,2,2*n)l[i]=i-1;
        rep(i,1,2*n-1)r[i]=i+1;
        l[1]=2*n;r[2*n]=1;
        int pos=1,cnt=0;
        while(cnt<n){
            int c=1;
            while(c<m){
                c++;
                pos=r[pos];
            }
            cnt++;
            l[r[pos]]=l[pos];
            r[l[pos]]=r[pos];
            ans[pos]=1;
            pos=r[pos];
        }
        rep(i,1,2*n){
            putchar(ans[i]?'B':'G');
            if(i%50==0)putchar('\n');
        }
        putchar('\n');
        putchar('\n');
    }
    return 0;
}