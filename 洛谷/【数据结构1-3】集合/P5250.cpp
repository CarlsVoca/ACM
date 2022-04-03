#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

set<int> s;

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int t,l;
        scanf("%d%d",&t,&l);
        if(t==1){
            if(s.empty()){s.insert(l);continue;}
            set<int>::iterator it=lower_bound(s.begin(),s.end(),l);
            if(it==s.end()||(*it)!=l){s.insert(l);continue;}
            else puts("Already Exist");
        }
        else{
            if(s.empty()){puts("Empty");continue;}
            set<int>::iterator it=lower_bound(s.begin(),s.end(),l);
            if(it==s.end()){printf("%d\n",*(prev(it)));s.erase(prev(it));}
            else if(it==s.begin()){printf("%d\n",*it);s.erase(it);}
            else{
                int ll=*prev(it),rr=*it;
                if(abs(ll-l)<=abs(rr-l)){
                    printf("%d\n",ll);
                    s.erase(prev(it));
                }
                else{
                    printf("%d\n",rr);
                    s.erase(it);
                }
            }
        }
    }
    return 0;
}