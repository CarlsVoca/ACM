#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct BigInteger{
	static const int base=100000000;
	static const int width=8;
	vector<int>s;
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
			int x=g;
			if(i<s.size())x+=s[i];
			if(i<b.s.size())x+=b.s[i];
			c.s.push_back(x%base);
			g=x/base;
		}
		return c;
	}
	BigInteger operator += (const BigInteger &b){
		*this=*this+b;
		return *this;
	}
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
istream& operator >> (istream &in,BigInteger &x)
{
	string s;
	if(!(in>>s))return in;
	x=s;
	return in;
}

int main()
{
	BigInteger a,b;
	cin>>a>>b;
	cout<<a+b;
	return 0;
}