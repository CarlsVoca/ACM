#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

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
		for(int i=0,g=0;;i++){
			if(g==0&&i>=s.size()&&i>=b.s.size())break;
			if(i<s.size())g+=s[i];
			if(i<b.s.size())g+=b.s[i];
			c.s.push_back(g%base);
			g/=base;
		}
		return c;
	}
	BigInteger operator += (const BigInteger &b){
		*this=*this+b;
		return *this;
	}
	BigInteger operator - (const BigInteger &b)const{
		BigInteger c;
		c.s.clear();
		for(int i=0,g=0;;i++){
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
};
ostream& operator << (ostream &out,const BigInteger &x){
	out<<x.s.back();
	for(int i=x.s.size()-2;i>=0;i--){
		char buf[20];
		sprintf(buf,"%08d",x.s[i]);
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

int main()
{
	BigInteger a,b;
	cin>>a>>b;
	cout<<a*b<<endl;
	return 0;
}

