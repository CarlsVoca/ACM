#include<bits/stdc++.h>

using namespace std;

string s;
int cnt[11];

int main(){
    cin >> s;
    int n=s.length();
    for(int i=0;i<n;i++){
        cnt[s[i]-'0']++;
        if(s[i]!='5')cnt[5]++;
        else cnt[5]--;
    }
    for(int i=1;i<=9;i++)printf("%d ",cnt[i]);
    return 0;
}