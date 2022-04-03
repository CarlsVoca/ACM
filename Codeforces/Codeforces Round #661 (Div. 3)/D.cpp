#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int p[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        // puts("Carls");
        queue<int> q0,q1;
        int cnt=0;
        rep(i,0,n-1){
            if(s[i]=='0'){
                if(q0.empty()){
                    p[i]=(++cnt);
                    q1.push(i);
                }
                else{
                    p[i]=p[q0.front()];
                    q0.pop();
                    q1.push(i);
                }
            }
            else if(s[i]=='1'){
                if(q1.empty()){
                    p[i]=(++cnt);
                    q0.push(i);
                }
                else{
                    p[i]=p[q1.front()];
                    q1.pop();
                    q0.push(i);
                }
            }
        }
        printf("%d\n",cnt);
        rep(i,0,n-1)printf("%d ",p[i]);
        putchar('\n');
    }
    return 0;
}