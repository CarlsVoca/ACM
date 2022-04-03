#include<bits/stdc++.h>

using namespace std;

int f[10];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=8;i++)f[i]=i;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<8;i++){
            if(s[i]=='1')cnt++;
        }
        if(cnt==7){puts("Yes");continue;}
        bool flag=1;
        for(int i=1;i<=8;i++){
            if(s[i-1]=='0'&&s[(i+2)%8]=='1'&&s[(i+4)%8]=='1'){
                flag=0;
                break;
            }
            else if(s[i-1]=='0'){
                if(s[(i+2)%8]=='0')f[find(i)]=find((i+2)%8+1);
                if(s[(i+4)%8]=='0')f[find(i)]=find((i+4)%8+1);
            }
        }
        int num[10];
        memset(num,0,sizeof(num));
        for(int i=1;i<=8;i++)num[find(i)]++;
        bool flag2=0;
        for(int i=1;i<=8;i++)if(num[i]==8-cnt)flag2=1;
        if(flag&&flag2)puts("Yes");
        else puts("No");
    }
    return 0;
}