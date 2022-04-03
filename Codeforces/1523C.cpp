#include<bits/stdc++.h>

using namespace std;

stack< vector<int> > s;

void print(vector<int> v){
    for(int i=0;i<v.size();i++)cout<<v[i]<<".\n"[i==(int)v.size()-1];
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        while(!s.empty())s.pop();
        vector<int> c;c.clear();s.push(c);
        int n;
        scanf("%d",&n);
        while(n--){
            int x;
            scanf("%d",&x);
            if(x==1){
                vector<int> tmp=s.top();
                tmp.push_back(1);
                s.push(tmp);
                print(tmp);
            }
            else{
                while(s.top()[s.top().size()-1]!=x-1)s.pop();
                vector<int> tmp=s.top();s.pop();
                tmp[tmp.size()-1]=x;
                s.push(tmp);
                print(tmp);
            }
        }
    }
    return 0;
}