#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

namespace Big_Integer{
    struct BigInteger{
        static const int base=100000000;
        BigInteger(long long num=0){*this=num;}
        static const int width=8;
        vector<long long>s;
        BigInteger operator = (long long num){
            s.clear();
            do{
                s.push_back(num%base);
                num/=base;
            }while(num);
            return *this;
        }
        BigInteger operator = (const string &str){
            s.clear();
            int x,len=(str.length()-1)/width+1;
            for(int i=0;i<len;i++){
                int end=str.length()-i*width;
                int start=max(0,end-width);
                sscanf(str.substr(start,end-start).c_str(),"%d",&x);
                s.push_back(x);
            }
            return *this;
        }
        BigInteger operator + (const BigInteger &b)const{
            BigInteger c;
            c.s.clear();
            for(unsigned int i=0,g=0;;i++){
                if(g==0&&i>=s.size()&&i>=b.s.size())break;
                if(i<s.size())g+=s[i];
                if(i<b.s.size())g+=b.s[i];
                c.s.push_back(g%base);
                g/=base;
            }
            return c;
        }
        BigInteger operator - (const BigInteger &b)const{
            BigInteger c;
            c.s.clear();
            for(unsigned int i=0,g=0;;i++){
                if(i>=s.size())break;
                if(i>=b.s.size()){
                    c.s.push_back(s[i]+g);
                    g=0;
                }
                else{
                    if(s[i]<b.s[i]){
                        c.s.push_back(s[i]-b.s[i]+base+g);
                        g=-1;
                    }
                    else{
                        c.s.push_back(s[i]-b.s[i]+g);
                        g=0;
                    }
                }
            }
            return c;
        }
        BigInteger operator * (const BigInteger &b)const{
            BigInteger c;
            c.s.clear();
            for(unsigned int i=0;i<s.size()+b.s.size();i++)c.s.push_back(0);
            for(unsigned int i=0;i<s.size();i++)
              for(unsigned int j=0;j<b.s.size();j++){
                  c.s[i+j]+=s[i]*b.s[j];
              }
            for(unsigned int i=0;i<c.s.size()-1;i++){
                c.s[i+1]+=c.s[i]/base;
                c.s[i]=c.s[i]%base;
            }
            while(c.s.back()==0&&c.s.size()>1)c.s.erase(c.s.end()-1);
            return c;
        }
        BigInteger operator / (const long long &b)const{
            BigInteger c;
            c.s.clear();c.s.resize(s.size());
            long long res=0;
            for(int i=s.size()-1;i>=0;i--){
                res*=base;
                res+=s[i];
                c.s[i]=res/b;
                res%=b;
            }
            while(c.s.back()==0&&c.s.size()>1)c.s.erase(c.s.end()-1);
            return c;
        }
        long long operator % (const long long &b)const{
            BigInteger c;
            c.s.clear();c.s.resize(s.size());
            long long res=0;
            for(int i=s.size()-1;i>=0;i--){
                res*=base;
                res+=s[i];
                c.s[i]=res/b;
                res%=b;
            }
            while(c.s.back()==0&&c.s.size()>1)c.s.erase(c.s.end()-1);
            return res;
        }
        BigInteger operator += (const BigInteger &b){
            *this=*this+b;
            return *this;
        }
        BigInteger operator -= (const BigInteger &b){
            *this=*this-b;
            return *this;
        }
        BigInteger operator *= (const BigInteger &b){
            *this=*this*b;
            return *this;
        }
        BigInteger operator /= (const long long &b){
            *this=*this/b;
            return *this;
        }
        BigInteger operator %= (const long long &b){
            *this=*this%b;
            return *this;
        }
        bool operator < (const BigInteger &b)const{
            if(s.size()!=b.s.size())return s.size()<b.s.size();
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]!=b.s[i])return s[i]<b.s[i];
            }
            return 0;
        }
        bool operator > (const BigInteger &b)const{return b < *this;}
        bool operator <= (const BigInteger &b)const{return !(*this>b);}
        bool operator != (const BigInteger &b)const{return (b<*this)||(b>*this);}
    };
    ostream& operator << (ostream &out,const BigInteger &x){
        out<<x.s.back();
        for(int i=x.s.size()-2;i>=0;i--){
            char buf[20];
            sprintf(buf,"%08lld",x.s[i]);
            for(unsigned int j=0;j<strlen(buf);j++)out<<buf[j];
        }
        return out;
    }
    istream& operator >> (istream &in,BigInteger &x){
        string s;
        if(!(in>>s))return in;
        x=s;
        return in;
    }
}
using namespace Big_Integer;

BigInteger fac[1005];

int main(){
    fac[0]=1;
    rep(i,1,1000)fac[i]=fac[i-1]*i;
    int T;
    scanf("%d",&T);
    while(T--){
        int n,a;
        LL ans=0;
        scanf("%d%d",&n,&a);
        BigInteger tmp=fac[n];
        LL z=0;
        while(tmp!=z){
            if(tmp%10==a)ans++;
            tmp/=10;
        }
        printf("%d\n",ans);
    }
    return 0;
}