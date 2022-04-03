#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

struct Data{
	int l,r;
	bool operator < (const Data &b)const{
		return 1LL*b.l*b.r>1LL*l*r;
	}
}d[maxn];

namespace Big_Integer{
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
		BigInteger operator % (const long long &b)const{
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

int main(){
	int n;
	scanf("%d",&n);
	BigInteger a,b;
	cin>>a>>b;
	for(int i=1;i<=n;i++)scanf("%d%d",&d[i].l,&d[i].r);
	sort(d+1,d+n+1);
	BigInteger ans=a;
	for(int i=1;i<=n;i++){
		ans=(a/d[i].r>ans?a/d[i].r:ans);
		a*=d[i].l;
	}
	cout<<ans<<endl;
	return 0;
}