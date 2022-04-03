#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5005;

namespace BigInteger{
	struct BigInteger{
		static const int base=100000000;
		static const int width=8;
		vector<long long>s;
		BigInteger(long long num=0){*this=num;}
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
				if(start==end-1&&str[start]=='-'){s[s.size()-1]=-s[s.size()-1];break;}
				sscanf(str.substr(start,end-start).c_str(),"%d",&x);
				s.push_back(x);
			}
			if(s[s.size()-1]<0){
				for(int i=0;i<s.size()-1;i++)s[i]=-s[i];
			}
			return *this;
		}
		BigInteger operator - ()const{
			BigInteger c=*this;
			for(int i=0;i<c.s.size();i++)c.s[i]=-c.s[i];
			return c;
		}
		BigInteger operator + (const BigInteger &b)const{
			BigInteger c;
			c.s.clear();
			for(int i=0;i<max(s.size(),b.s.size());i++){
				if(i>=s.size())c.s.push_back(b.s[i]);
				else if(i>=b.s.size())c.s.push_back(s[i]);
				else c.s.push_back(s[i]+b.s[i]);
			}
			while(c.s.back()==0&&c.s.size()>1)c.s.erase(c.s.end()-1);
			for(int i=c.s.size()-1;i>=1;i--){
				if(c.s[i]>0){c.s[i]--;c.s[i-1]+=base;}
				if(c.s[i]<0){c.s[i]++;c.s[i-1]-=base;}
			}
			for(int i=0;;i++){
				if(i==c.s.size()-1){
					if(c.s[i]/base)c.s.push_back(c.s[i]/base),c.s[i]%=base;
					else break;
				}
				else{
					c.s[i+1]+=c.s[i]/base;
					c.s[i]%=base;
				}
			}
			while(c.s.back()==0&&c.s.size()>1)c.s.erase(c.s.end()-1);
			return c;
		}
		BigInteger operator += (const BigInteger &b){
			*this=*this+b;
			return *this;
		}
		BigInteger operator - (const BigInteger &b)const{
			return *this+(-b);
		}
		BigInteger operator * (const BigInteger &b)const{
			BigInteger c;
			c.s.clear();
			for(int i=0;i<s.size()+b.s.size();i++)c.s.push_back(0);
			for(int i=0;i<s.size();i++)
			  for(int j=0;j<b.s.size();j++){
			  	c.s[i+j]+=s[i]*b.s[j];
			  }
			for(int i=0;i<c.s.size()-1;i++){
				c.s[i+1]+=c.s[i]/base;
				c.s[i]=c.s[i]%base;
			}
			while(c.s.back()==0&&c.s.size()>1)c.s.erase(c.s.end()-1);
			return c;
		}
		BigInteger operator *= (const BigInteger &b){
			*this=*this*b;
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
		bool operator == (const BigInteger &b)const{return s.size()==b.s.size()&&s[s.size()-1]==b.s[b.s.size()-1];}
	}f[maxn];
	ostream& operator << (ostream &out,const BigInteger &x){
		out<<x.s.back();
		for(int i=x.s.size()-2;i>=0;i--){
			char buf[20];
			sprintf(buf,"%08d",abs(x.s[i]));
			for(int j=0;j<strlen(buf);j++)out<<buf[j];
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
using namespace BigInteger;

int main(){
	int n;
	scanf("%d",&n);
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++)f[i]=f[i-1]+f[i-2];
	if(!n)cout<<0<<endl;
	else cout<<f[n]<<endl;
	return 0;
}