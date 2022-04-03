#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

string s;
int cnt[30];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        cin>>s;
        int n=s.length();
        int tp=0;
        rep(i,0,n-1){
            if(cnt[s[i]-'a']==0)tp++;
            cnt[s[i]-'a']++;
        }
        bool flag=0;
        rep(i,0,25){
            if(cnt[i]==1){
                putchar(i+'a');
                cnt[i]--;
                rep(j,0,25){
                    rep(k,1,cnt[j])putchar(j+'a');
                }
                putchar('\n');
                flag=1;
                break;
            }
        }
        if(flag)continue;
        int fist=-1,oth_cnt=0;
        rep(i,0,25){
            if(cnt[i]){
                if(fist==-1){
                    fist=i;
                }
                else{
                    oth_cnt+=cnt[i];
                }
            }
        }
        if(oth_cnt>=cnt[fist]-2){
            putchar(fist+'a');putchar(fist+'a');
            cnt[fist]-=2;
            int tmp=fist+1;
            while(cnt[fist]){
                while(!cnt[tmp])tmp++;
                putchar(tmp+'a');
                putchar(fist+'a');
                cnt[tmp]--;
                cnt[fist]--;
            }
            rep(i,0,25){
                rep(j,1,cnt[i])putchar(i+'a');
            }
            putchar('\n');
        }
        else{
            if(tp==1){          
                rep(i,0,25){
                    rep(j,1,cnt[i])putchar(i+'a');
                }
                putchar('\n');
            }
            else if(tp==2){
                putchar(fist+'a');cnt[fist]--;
                int oth;
                rep(i,fist+1,25)if(cnt[i]){oth=i;break;}
                while(cnt[oth]){putchar(oth+'a');cnt[oth]--;}
                while(cnt[fist]){putchar(fist+'a');cnt[fist]--;}
                putchar('\n');
            }
            else{
                putchar(fist+'a');cnt[fist]--;
                int sec,thd;
                rep(i,fist+1,25)if(cnt[i]){sec=i;break;}
                rep(i,sec+1,25)if(cnt[i]){thd=i;break;}
                putchar(sec+'a');cnt[sec]--;
                while(cnt[fist]){putchar(fist+'a');cnt[fist]--;}
                putchar(thd+'a');cnt[thd]--;
                rep(i,0,25){
                    rep(j,1,cnt[i])putchar(i+'a');
                }
                putchar('\n');
            }
        }
    }
    return 0;
}