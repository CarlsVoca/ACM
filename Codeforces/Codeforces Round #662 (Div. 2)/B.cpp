#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int cnt[maxn],a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int cnt8=0,cnt6=0,cnt2=0,cnt4=0;
    rep(i,1,1e5){
        if(cnt[i]>=8)cnt8++;
        else if(cnt[i]>=6)cnt6++;
        else if(cnt[i]>=4)cnt4++;
        else if(cnt[i]>=2)cnt2++;
    }
    int m;
    scanf("%d",&m);
    rep(i,1,m){
        char op;
        int x;
        cin>>op>>x;
        if(op=='+'){
            cnt[x]++;
            if(cnt[x]==2)cnt2++;
            else if(cnt[x]==4)cnt4++,cnt2--;
            else if(cnt[x]==6)cnt6++,cnt4--;
            else if(cnt[x]==8)cnt8++,cnt6--;
        }
        else{
            cnt[x]--;
            if(cnt[x]==1)cnt2--;
            else if(cnt[x]==3)cnt4--,cnt2++;
            else if(cnt[x]==5)cnt6--,cnt4++;
            else if(cnt[x]==7)cnt8--,cnt6++;
        }
        if(cnt8>=1||(cnt6>=1&&(cnt4>=1||cnt2>=1))||(cnt4>=2||cnt6>=2)||((cnt6>=1||cnt4>=1)&&cnt2>=2))puts("YES");
        else puts("NO");
    }
    return 0;
}