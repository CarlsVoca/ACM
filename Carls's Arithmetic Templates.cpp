/*********************************************************************
				Carls's Arithmetic Templates
*********************************************************************/

//Fast IO 快读
namespace Fast_IO{
	void read(int &x){
		x=0;int flag=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;if(ch==EOF)return;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
		x*=flag;
	}
}

//Quick Sort 快速排序
namespace Quick_Sort{
	void do_main(int arr[],int size){
    	int i,j,base;
    	i=1;j=size;
    	base=arr[i+j>>1];
    	while(i<=j){
    	    while(arr[i]<base)i++;
    	    while(arr[j]>base)j--;
    	    if (i<=j){
    	        swap(arr[i],arr[j]);
    	        i++;j--;
    	    }
    	}
	    if(1<j)do_main(1,j);
		if(i<size)do_main(i,size);
	}
}

//Bubble Sort 冒泡排序
namespace Bubble_Sort{
	void do_main(int arr[],int size){
    	int flag=0;
    	int pre=size;
    	while(pre){
    		flag=0;
    		for(int i=1;i<=pre-1;i++){
        		if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]),flag=i+1;
    		}
    		pre=flag;
    	}
	}
}

//Insert Sort 插入排序
namespace Insert_Sort{
	void do_main(int arr[],int size){
		for(int i=2;i<=size;i++)
			for(int j=i-1;j&&arr[j]>arr[j+1];j++){
				swap(arr[j],arr[j+1]);
			}
	}
}

//Shell Sort 希尔排序
namespace Shell_Sort{
	void do_main(int arr[],int size){
		for(int gap=size>>1;gap;gap>>=1)
			for(int i=gap+1;i<=n;i++)
				for(int j=i-gap;j>0&&a[j]>a[j+gap];j+=gap){
					swap(a[j],a[j+gap]);
				}
	}
}

//Selection Sort 选择排序
namespace Selection_Sort{
	void do_main(int arr[],int size){
		int MIN=INF;
		int minnode=0;
		for(int i=1;i<=size;i++){
			MIN=INF;
    		for(int j=i;j<=size;j++){
    	    	if(arr[j]<min)minnode=j,MIN=arr[j];
    		}
    		swap(arr[i],arr[minnode]);
    	}
	}
}

//Merge Sort 归并排序
namespace Merge_Sort{
	int T[maxn];
	void do_main(int arr[],int l,int r){
		if(l>=r)return;
		int mid=l+r>>1;
		do_main(arr,l,mid);
		do_main(arr,mid+1,r);
		int x=l,y=mid+1,z=l;
		while(x<=mid||y<=r){
			if(y>r||(x<=mid&&arr[x]<=arr[y]))T[z++]=arr[x++];
			else T[z++]=arr[y++]/*,cnt+=mid-x+1 (Query the number of inversions) */;
		}
		for(int i=l;i<=r;i++)arr[i]=T[i];
	}
}

//Radix Sort 基数排序
namespace Radix_Sort{
	const int base=1<<16;
	vector<int>r[base];
	void do_main(int arr[],int size){
		bool flag=1;
		LL d=base;
		while(flag){
			flag=0;
			for(int i=1;i<=size;i++){
				r[(arr[i]/(d/base))%d].push_back(arr[i]);
				if(arr[i]/d)flag=1;
			}
			int cnt=0;
			for(int i=0;i<base;i++){
				for(int j=0;j<r[i].size();j++){
					arr[++cnt]=r[i][j];
				}
			}
			d*=base;
			for(int i=0;i<base;i++)r[i].resize(0);
		}
	}
}

//Binary Search 二分查找/二份答案
namespace Binary_Search{
	bool check(int x){
		//......
	}
	double do_main(){
		int l=/*二分下界*/,r=/*二分上界*/;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		return l;
	}
}

//Ternary-Search 三分查找
namespace Ternary_Search{
	double EPS=1;
	double f(double x){
		//......
	}
	double do_main(double l,double r){
    	while(r-l>EPS){
        	double mid=(l+r)/2;
        	double midd=(mid+r)/2;
        	if(f(mid)>f(midd))r=midd;
        	else l=mid;
    	}
    	return l;
	}
}

//BigInteger
namespace Big_Integer{
	struct BigInteger{
		static const int base=100000000;
		static const int width=8;
		vector<long long>s;
		BigInteger(){*this=0;}
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
		BigInteger(long long num){*this=num;}
		BigInteger(string num){*this=num;}
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
		BigInteger operator + (const long long &b)const{return *this+(BigInteger)b;}
		BigInteger operator + (const string &b)const{return *this+(BigInteger)b;}
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
		BigInteger operator - (const long long &b)const{return *this-(BigInteger)b;}
		BigInteger operator - (const string &b)const{return *this-(BigInteger)b;}
		BigInteger operator * (const BigInteger &b)const{
			BigInteger c;
			c.s.clear();
			for(unsigned int i=0;i<s.size()+b.s.size();i++)
				c.s.push_back(0);
			for(unsigned int i=0;i<s.size();i++)
				for(unsigned int j=0;j<b.s.size();j++)
				{
					c.s[i+j]+=s[i]*b.s[j];
				}
			for(unsigned int i=0;i<c.s.size()-1;i++)
			{
				c.s[i+1]+=c.s[i]/base;
				c.s[i]=c.s[i]%base;
			}
			while(c.s.back()==0&&c.s.size()>1)
				c.s.erase(c.s.end()-1);
			return c;
		}
		BigInteger operator * (const long long &b)const{return (*this)*(BigInteger)b;}
		BigInteger operator * (const string &b)const{return (*this)*(BigInteger)b;}
		BigInteger operator / (const long long &b)const{
			BigInteger c;
			c.s.clear();
			c.s.resize(s.size());
			long long res=0;
			for(int i=s.size()-1;i>=0;i--)
			{
				res*=base;
				res+=s[i];
				c.s[i]=res/b;
				res%=b;
			}
			while(c.s.back()==0&&c.s.size()>1)
				c.s.erase(c.s.end()-1);
			return c;
		}
		BigInteger operator % (const long long &b)const{
			BigInteger c;
			c.s.clear();
			c.s.resize(s.size());
			long long res=0;
			for(int i=s.size()-1;i>=0;i--)
			{
				res*=base;
				res+=s[i];
				c.s[i]=res/b;
				res%=b;
			}
			while(c.s.back()==0&&c.s.size()>1)
				c.s.erase(c.s.end()-1);
			return (BigInteger)res;
		}
		BigInteger operator += (const BigInteger &b){return *this=*this+b;}
		BigInteger operator += (const long long &b){return *this+=(BigInteger)b;}
		BigInteger operator += (const string &b){return *this+=(BigInteger)b;}
		BigInteger operator -= (const BigInteger &b){return *this=*this-b;}
		BigInteger operator -= (const long long &b){return *this-=(BigInteger)b;}
		BigInteger operator -= (const string &b){return *this-=(BigInteger)b;}
		BigInteger operator *= (const BigInteger &b){return *this=(*this)*b;}
		BigInteger operator *= (const long long &b){return (*this)*=(BigInteger)b;}
		BigInteger operator *= (const string &b){return (*this)*=(BigInteger)b;}
		BigInteger operator /= (const long long &b){return *this=*this/b;}
		BigInteger operator %= (const long long &b){return *this=*this%b;}
		bool operator < (const BigInteger &b)const{
			if(s.size()!=b.s.size())
				return s.size()<b.s.size();
			for(int i=s.size()-1;i>=0;i--)
			{
				if(s[i]!=b.s[i])
					return s[i]<b.s[i];
			}
			return 0;
		}
		bool operator < (const long long &b)const{return *this<(BigInteger)b;}
		bool operator < (const string &b)const{return *this<(BigInteger)b;}
		bool operator > (const BigInteger &b)const{return b<*this;}
		bool operator > (const long long &b)const{return *this>(BigInteger)b;}
		bool operator > (const string &b)const{return *this>(BigInteger)b;}
		bool operator <= (const BigInteger &b)const{return !(*this>b);}
		bool operator <= (const long long &b)const{return *this<=(BigInteger)b;}
		bool operator <= (const string &b)const{return *this<=(BigInteger)b;}
		bool operator >= (const BigInteger &b)const{return !(*this<b);}
		bool operator >= (const long long &b)const{return *this>=(BigInteger)b;}
		bool operator >= (const string &b)const{return *this>=(BigInteger)b;}
		bool operator == (const BigInteger &b)const{return !(*this<b)&&!(*this>b);}
		bool operator == (const long long &b)const{return *this==(BigInteger)b;}
		bool operator == (const string &b)const{return *this==(BigInteger)b;}
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

//Discretization
namespace Discretization{
	int tmp[maxn];
	void do_main(int arr[],int size){
		memcpy(tmp+1,arr+1,size<<?);//int:?=2;long long:?=4;
		sort(tmp+1,tmp+size+1);
		int m=unique(tmp+1,tmp+size+1)-tmp-1;
		for(int i=1;i<=size;i++)arr[i]=lower_bound(tmp+1,tmp+m+1,arr[i])-tmp;
	}
}

//Segment Tree
namespace Segment_Tree{
	struct Node{
	    int l,r
		LL sum,lazy;
	}t[maxn<<2];
	inline void update(int k){
    	t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
	}
	void build(int k,int l,int r){
    	t[k].l=l;t[k].r=r;t[k].lazy=0;
    	if(l==r){
    	    t[k].sum=val[l];
    	    return;
    	}
    	int mid=(l+r)>>1;
    	build(k<<1,l,mid);
    	build(k<<1|1,mid+1,r);
   		update(k);
	}
	inline void pushdown(int k){
		if(t[k].lazy==0)return;
	    t[k<<1].sum+=t[k].lazy*(t[k<<1].r-t[k<<1].l+1);
    	t[k<<1].lazy+=t[k].lazy;
		t[k<<1|1].sum+=t[k].lazy*(t[k<<1|1].r-t[k<<1|1].l+1);
    	t[k<<1|1].lazy+=t[k].lazy;
		t[k].lazy=0;
	}
	void change_interval(int k,int L,int R,LL k){
    	if(L>t[k].r||R<t[k].l)return;
    	if(L<=t[k].l&&R>=t[k].r){
    	    t[k].lazy+=k;
    	    t[k].sum+=k*(t[k].r-t[k].l+1);
    	    return;
    	}
    	pushdown(k);
    	change_interval(k<<1,L,R,k);
    	change_interval(k<<1|1,L,R,k);
    	update(k);
	}
	LL query_interval(int k,int L,int R){
    	if(L>t[k].r||R<t[k].l)return 0;
    	if(L<=t[k].l&&R>=t[k].r){
    	    return t[k].sum;
    	}
    	pushdown(k);
    	return query(k<<1,L,R)+query(k<<1|1,L,R);
	}
}

//Cantor
namespace Cantor{
	struct State{
		int ch[maxn];
		int num;
		State(){
			//......
		}
	};
	int fac[maxn];
	void pre(){
		fac[0]=1;
		for(int i=1;i<maxn;i++){
			fac[i]=fac[i-1]*i;
		}
	}
	int do_main(State &a){
		a.num=0;
		for(int i=0;i<n;i++){
			int cnt=0;
			for(int j=0;j<i;j++){
				if(a.ch[j]>a.ch[i])cnt++;
			}
			a.num+=fac[i]*cnt;
		}
		return ++a.num;
	}
}

//A-Star Search
namespace A_Star_Search{
	bool vis[maxn];
	struct State{
		//......
		int g,h;
		int num;
		State(){
			//......
		}
		bool operator < (const State &b)const{
			return g==b.g?h>b.h:g>b.g;
		}
	};
	int guess(State &a){
		a.h=0;
		//......
		return a.h;
	}
	void do_main(State s,State t){
		Hash::pre();
		priority_queue<State>q;
		memset(vis,0,sizeof(vis));
		Hash::do_main(t);
		Hash::do_main(s);guess(s);s.g=0;
		q.push(s);
		vis[s.num]=1;
		while(!q.empty()){
			State now=q.top();
			q.pop();
			if(now.num==t.num){
				//......
				return;
			}
			for(int i=0;i<4;i++){
				State to=now;
				//......
				if(/*......*/||vis[Hash::do_main(to)])continue;
				to.g++;
				vis[to.num]=1;
				guess(to);
				q.push(to);
			}
		}
	}
}

//SPFA
namespace SPFA{
	int cnt[maxn];
	bool vis[maxn];
	bool do_main(int s){
		queue<int>q;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		vis[s]=1;
		dis[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=0;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dis[v]>dis[u]+e[i].w){
					dis[v]=dis[u]+e[i].w;
					if(!vis[v]){
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
		return 1;
	}
}

//Dijkstra
namespace Dijkstra{
	typedef pair<int,int> pii;
	void do_main(int s){
		priority_queue< pii,vector<pii>,greater<pii> >q;
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		q.push(pii(0,s));
		while(!q.empty()){
			pii now=q.top();q.pop();
			int u=now.second;
			if(dis[u]<now.first)continue;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dis[u]+e[i].w<dis[v]){
					dis[v]=dis[u]+e[i].w;
					q.push(pii(dis[v],v));
				}
			}
		}
	}
}

//Floyd
namespace Floyd{
	void do_main(){
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
	}
}

//Union-Find
namespace Union_Find{
	int f[maxn],Rank[maxn];
	void Pre(int n){
		memset(Rank,0,sizeof(Rank));
		for(int i=1;i<=n;i++)f[i]=i;
	}
	int Find(int x){
		return f[x]==x?x:f[x]=Find(f[x]);
	}
	void Union(int x,int y){
		int fx=Find(x),fy=Find(y);
		if(fx!=fy){
			if(Rank[fx]>Rank[fy])f[fy]=fx;
			else{
				f[fx]=fy;
				if(Rank[fx]==Rank[fy])Rank[fy]++;
			}
		}
	}
}

//Kruskal
namespace Kruskal{
	int do_main(){
		Union_Find::pre();
		int cnt=0;
		sort(e+1,e+nume+1);
		for(int i=1;i<=nume;i++){
			int fu=Union_Find::find(e[i].u),fv=Union_Find::find(e[i].v);
			if(fu!=fv){
				Union_Find::f[fu]=fv;
				ans+=e[i].w;
				if(++cnt==n-1)break;
			}
		}
		if(cnt!=n-1)return ans=-1;
		else return ans;
	}
}

//Boruvka
namespace Boruvka{
	int MIN[maxn],pos[maxn];
	using namespace Union_Find;
	int do_main(){
		bool flag=0;
		int ret=0;
		while(1){
			flag=0;
			memset(MIN,0x3f,sizeof(MIN));
			for(int u=1;u<=n;u++){
				int fu=Find(u);
				for(int i=last[u];i;i=e[i].nxt){
					int v=e[i].v;
					int fv=Find(v);
					if(fu!=fv&&e[i].w<MIN[f[u]]){
						MIN[f[u]]=e[i].w;
						pos[f[u]]=f[v];
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(MIN[i]!=INF&&Find(i)!=Find(pos[i])){
					flag=1;
					Union(i,pos[i]);
					ret+=MIN[i];
				}
			}
			if(!flag)break;
		}
		return ret;
	}
}

//MP
namespace MP{
	int f[maxn];
	void Get_Fail(char *P){
		int lenp=strlen(P+1);
		f[1]=0;
		for(int i=2;i<=lenp;i++){
			int j=f[i-1];
			while(j&&P[j+1]!=P[i])j=f[j];
			f[i]=P[j+1]==P[i]?j+1:0;
		}
	}
	int do_main(char *T,char *P){
		int res=0;
		int lent=strlen(T+1),lenp=strlen(P+1);
		Get_Fail(P);
		int j=0;
		for(int i=1;i<=lent;i++){
			while(j&&T[i]!=P[j+1])j=f[j];
			if(T[i]==P[j+1])j++;
			if(j==lenp){
				j=f[j];
				res++;
			}
		}
		return res;
	}
}

//Manacher
namespace Manacher{
	char tmp[maxn<<1];
	int p[maxn<<1];
	int do_main(char *s){
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)tmp[i*2-1]='%',tmp[i*2]=s[i];
		tmp[len=len*2+1]='%';
		int pos=0,R=0;
		int MAX=0;
		for(int i=1;i<=len;i++){
			if(i<R)p[i]=min(p[pos*2-i],R-i);else p[i]=1;
			while(i-p[i]>=1&&i+p[i]<=len&&tmp[i-p[i]]==tmp[i+p[i]])p[i]++;
			if(i+p[i]>R)pos=i,R=i+p[i];
			MAX=max(MAX,p[i]-1);
		}
		return MAX;
	}
}

//Trie
namespace Trie{
	struct Tire{
		static const int sigma_size=30;
		int ch[maxn][sigma_size];
		int val[maxn];
		int prefix[maxn];
		int size;
		void reset(){
			size=1;
			memset(ch,0,sizeof(ch));
			memset(val,0,sizeof(val));
			memset(prefix,0,sizeof(prefix));
		}
		int idx(char c){
			return c-'a';
		}
		void insert(char *s,int v){
			int u=0,n=strlen(s);
			for(int i=0;i<n;i++){
				int c=idx(s[i]);
				if(!ch[u][c]){
					ch[u][c]=size++;
				}
				u=ch[u][c];
				prefix[u]++;
			}
			val[u]=v;
		}
		int query_val(char *s){//Query the value of s
			int u=0,n=strlen(s);
			for(int i=0;i<n;i++){
				int c=idx(s[i]);
				if(!ch[u][c])return 0;
				u=ch[u][c];
			}
			return val[u];
		}
		int query_prefix(char *s){//Query the number of words prefixed with s
			int u=0,n=strlen(s);
			for(int i=0;i<n;i++){
				int c=idx(s[i]);
				if(!ch[u][c])return 0;
				u=ch[u][c];
			}
			return prefix[u];
		}
	}tire;
}

//Aho-Corasick Automaton
namespace Aho_Corasick_Automaton{
	struct Aho_Corasick_Automaton{
		static const int sigma_size=26;
		int ch[maxn][sigma_size];
		int val[maxn],last[maxn];
		int f[maxn];
		int size;
		void reset(){
			memset(ch,0,sizeof(ch));
			memset(val,0,sizeof(val));
			memset(last,0,sizeof(last));
			memset(f,0,sizeof(f));
			size=1;
		}
		int idx(char c){
			return c-'a';
		}
		void insert(char *P,int v){
			int u=0,n=strlen(P);
			for(int i=0;i<n;i++){
				int c=idx(P[i]);
				if(!ch[u][c]){
					ch[u][c]=++size;
				}
				u=ch[u][c];
			}
			val[u]=v;
		}
		void get_fail(){
			queue<int>q;
			f[0]=0;
			for(int c=0;c<sigma_size;c++){
				int u=ch[0][c];
				if(u){
					f[u]=0;
					q.push(u);
					last[u]=0;
				}
			}
			while(!q.empty()){
				int r=q.front();q.pop();
				for(int c=0;c<sigma_size;c++){
					int u=ch[r][c];
					if(!u){
						ch[r][c]=ch[f[r]][c];
						continue;
					}
					q.push(u);
					int v=f[r];
					while(v&&!ch[v][c])v=f[v];
					f[u]=ch[v][c];
					last[u]=val[f[u]]?f[u]:last[f[u]];
				}
			}
		}
		bool count(char *T){
			int u=0,n=strlen(T);
			for(int i=0;i<n;i++){
				int c=idx(T[i]);
				u=ch[u][c];
				if(val[u]||last[u])return 1;
			}
			return 0;
		}
	}ac;
}

//Quick Pow
namespace Quick_Pow{
	LL do_main(LL a,LL k){
    	LL r=1,base=a;
		while(k){
        	if(k&1)r=r*base;
        	base=base*base;
        	k>>=1;
    	}
    	return r;
	}
}

//Matrix Quick Pow
namespace Matrix_Quick_Pow{
	struct Matrix{
    	int arr[maxn][maxn];
    	Matrix operator * (const Matrix &b)const{
        	Matrix ret;
        	memset(ret.arr,0,sizeof(ret.arr));
            for(int i=0;i<=n-1;i++)
            	for(int j=0;j<=n-1;j++)
                	for(int k=0;k<=n-1;k++){
                		ret.arr[i][j]=(ret.arr[i][j]+arr[i][k]*b.arr[k][j])%mod;
                	}
            return ret;
       }
	};
	Matrix do_main(Matrix a,int k){
    	Matrix r;
    	memset(r.arr,0,sizeof(a.arr));
    	for(int i=0;i<n;i++)
        	for(int j=0;j<n;j++){
        	r.arr[i][j]=(i==j);
		}
		Matrix base=a;
    	while(k){
        	if(k&1)r=r*base;
        	base=base*base;
        	k>>=1;
    	}
    	return r;
	}
}

//Topo Sort
namespace Topo_Sort{
	int degree[maxn];
	int topo[maxn],num=0;
	queue<int>q;
	bool do_main(){
		for(int i=1;i<=n;i++){
			if(!degree[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			topo[++num]=u;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(--degree[v]==0)q.push(v);
			}
		}
		if(num!=n)return 1;
		else return 0;
	}
}

//Tree-Chain Division 树链剖分
namespace Tree_Chain_Division{
	int size[maxn],f[maxn],dep[maxn],son[maxn],top[maxn],id[maxn],real[maxn],val[maxn],num=0;
	void DFS_1(int u){
	    size[u]=1;
	    for(int i=last[u];i;i=e[i].nxt){
	        int v=e[i].v;
	        if(v!=f[u]){
	    	    f[v]=u;
	    	    dep[v]=dep[u]+1;
	    	    DFS_1(v);
	    	    size[u]+=size[v];
	    	    if(size[v]>size[son[u]])son[u]=v;
			}
		}
	}
	void DFS_2(int u,int tp){
	    top[u]=tp;
	    id[u]=++num;
	    real[num]=u;
	    if(son[u])DFS_2(son[u],tp);
	    for(int i=last[u];i;i=e[i].nxt){
	        int v=e[i].v;
	        if(v!=f[u]&&v!=son[u])DFS_2(v,v);
	    }
	}
	namespace Segment_Tree{
        struct Node{
            int l,r;
			LL sum,lazy;
        }t[maxn<<2];
        void update(int k){
            t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
        }
        void build(int k,int l,int r){
            t[k].l=l;t[k].r=r;t[k].lazy=0;
            if(l==r){
                t[k].sum=val[real[l]];
                return;
            }
            int mid=l+r>>1;
            build(k<<1,l,mid);
            build(k<<1|1,mid+1,r);
            update(k);
        }
        void pushdown(int k){
            if(t[k].lazy==0)return;
            t[k<<1].sum+=t[k].lazy*(t[k<<1].r-t[k<<1].l+1);
            t[k<<1].lazy+=t[k].lazy;
            t[k<<1|1].sum+=t[k].lazy*(t[k<<1|1].r-t[k<<1|1].l+1);
            t[k<<1|1].lazy+=t[k].lazy;
            t[k].lazy=0;
        }
        void change_interval(int k,int L,int R,LL x){
            if(t[k].l>R||t[k].r<L)return;
            if(t[k].l>=L&&t[k].r<=R){
                t[k].sum+=x*(t[k].r-t[k].l+1);
                t[k].lazy+=x;
                return;
            }
            pushdown(k);
            change_interval(k<<1,L,R,x);
            change_interval(k<<1|1,L,R,x);
            update(k);
        }
        LL query_interval(int k,int L,int R){
            if(t[k].l>R||t[k].r<L)return 0;
            if(t[k].l>=L&&t[k].r<=R){
                return t[k].sum;
            }
            pushdown(k);
            return query_interval(k<<1,L,R)+query_interval(k<<1|1,L,R);
        }
	}
	using namespace Segment_Tree;
	void change_road(int u,int v,LL x){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            change_interval(1,id[top[u]],id[u],x);
            u=f[top[u]];
        }
        if(dep[u]<dep[v])swap(u,v);
        change_interval(1,id[v],id[u],x);
    }
	LL query_road(int u,int v){
        LL res=0;
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            res+=query_interval(1,id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(dep[u]<dep[v])swap(u,v);
        res+=query_interval(1,id[v],id[u]);
        return res;
    }
    void change_root(int rt,int x){
        change_interval(1,id[rt],id[rt]+size[rt]-1,x);
    }
    LL query_root(int rt){
        return query_interval(1,id[rt],id[rt]+size[rt]-1);
    }
}

//Binary Indexed Tree
namespace Binary_Indexed_Tree{
	int c[maxn];
	void Change(int x,int k){
		for(;x<=n;x+=x&-x)c[x]+=k;
	}
	int Query(int x){
		int res=0;
		for(;x;x-=x&-x)res+=c[x];
		return res;
	}
	void Delete(int x){
		for(;x<=n;x+=x&-x)c[x]=0;
	}
}

//Gcd
namespace Gcd{
	int gcd(int x,int y){
		return y?gcd(y,x%y):x;
	}
}

//Exgcd
namespace Exgcd{
	void exgcd(int a,int b,int &x,int &y){
		if(!b)x=1,y=0;
		else{
			exgcd(b,a%b,y,x);
			y-=(a/b)*x;
		}
	}
}

//Sieve of Euler
namespace Sieve_of_Euler{
	int nump=0,prime[maxn];
	bool is_prime[maxn];
	void do_main(){
		memset(is_prime,1,sizeof(is_prime));
		is_prime[1]=0;
		for(int i=2;i<maxn;i++){
			if(is_prime[i])prime[++nump]=i;
			for(int j=1;j<=nump&&prime[j]*i<maxn;j++){
				is_prime[i*prime[j]]=0;
				if(i%prime[j]==0)break;
			}
		}
	}
}

//Euler's totient function
namespace Euler_totient_function{
	int euler[maxn];
	void Init(){
		for(int i=1;i<maxn;i++)euler[i]=i;
		for(int i=2;i<maxn;i++){
			if(euler[i]==i){
				for(int j=i;j<maxn;j+=i){
					euler[j]=euler[j]/i*(i-1);
				}
			}
		}
	}
	int Euler(int x){
		int res=x;
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				res=res/i*(i-1);
				while(x%i==0)x/=i;
			}
		}
		if(x>1)res=res/i*(i-1);
		return res;
	}
}

//LCA 最近公共祖先
namespace LCA{
	int dep[maxn],f[maxn][22];
	void dfs(int u){
		for(int i=last[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v!=f[u][0]){
				f[v][0]=u;
				dep[v]=dep[u]+1;
				dfs(v);
			}
		}
	}
	void pre(){
		for(int j=1;(1<<j)<=n;j++)
			for(int i=1;i<=n;i++){
				f[i][j]=f[f[i][j-1]][j-1];
			}
	}
	int do_main(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		int dif=dep[a]-dep[b];
		for(int i=0;(1<<i)<=dif;i++){
			if((1<<i)&dif)a=f[a][i];
		}
		if(a!=b){
			for(int i=(int)log2(n);i>=0;i--){
				if(f[a][i]!=f[b][i]){
					a=f[a][i];b=f[b][i];
				}
			}
			a=f[a][0];b=f[b][0];
		}
		return a;
	}
}

//Dinic
namespace Dinic{
/*
Note:
	memset(last,-1,sizeof(last));
	nume从0开始
*/
	int dep[maxn],pre[maxn];
	bool bfs(int s,int t){
		memset(dep,-1,sizeof(dep));
		dep[s]=0;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=last[u];~i;i=e[i].nxt){
				int v=e[i].v;
				if(dep[v]==-1&&e[i].f){
					dep[v]=dep[u]+1;
					q.push(v);
					if(v==t)return 1;
				}
			}
		}
		return 0;
	}
	LL dfs(int u,int t,LL cur){
		if(u==t)return cur;
		LL rest=cur;
		for(int &i=pre[u];~i;i=e[i].nxt){
			int v=e[i].v;
			if(dep[v]==dep[u]+1&&e[i].f){
				LL new_flow=dfs(v,t,min(e[i].f,rest));
				rest-=new_flow;
				e[i].f-=new_flow;
				e[i^1].f+=new_flow;
				if(!rest)return cur;
			}
		}
		return cur-rest;
	}
	LL do_main(int s,int t){
		LL res=0;
		while(bfs(s,t)){
			memcpy(pre,last,sizeof(last));
			res+=dfs(s,t,INF);
		}
		return res;
	}
}

//Hungarian
namespace Hungarian{
	int result[maxn];
	bool vis[maxn];
	bool dfs(int u){
		for(int i=last[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(!vis[v]){
				vis[v]=1;
				if(!result[v]||dfs(result[v])){
					result[v]=u;
					return 1;
				}
			}
		}
		return 0;
	}
	int do_main(){
		int cnt=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i))cnt++;
		}
		return cnt;
	}
}

//Tarjan
namespace Tarjan{
	int dfn[maxn],low[maxn];
	int sta[maxn],top;
	int dfnnum=0,colnum=0;
	bool vis[maxn];
	void do_main(int u){
		dfn[u]=low[u]=++dfnnum;
		vis[u]=1;
		sta[++top]=u;
		for(int i=last[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(!dfn[v]){
				do_main(v);
				low[u]=min(low[u],low[v]);
			}
			else if(vis[v])low[u]=min(low[u],dfn[v]);
		}
		if(dfn[u]==low[u]){
			colnum++;
			while(sta[top]!=u){
				color[sta[top]]=colnum;
				vis[sta[top]]=0;
				val[colnum]+=a[sta[top--]];
			}
			color[sta[top]]=colnum;
			vis[sta[top]]=0;
			val[colnum]+=a[sta[top--]];
		}
	}
}

//ST
namespace ST{
	int st[maxn][20];
	void Init(){
		for(int j=1;(1<<j)<=n;j++)
			for(int i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
			}
	}
	int query_max(int l,int r){
		int k=log2(r-l+1);
		return max(st[l][k],st[r-(1<<k)+1][k]);
	}
}

//Functional Treap
namespace Functional_Treap{
	typedef pair<int,int> pii;
	struct Node{
		int l,r,key,val,size;
	}t[maxn];
	int root,num=0;
	void update(int x){
		t[x].size=t[t[x].l].size+t[t[x].r].size+1;
	}
	int merge(int r1,int r2){
		if(!r1||!r2)return r1+r2;
		if(t[r1].key<t[r2].key){
			return t[r1].r=merge(t[r1].r,r2),update(r1),r1;
		}
		else{
			return t[r2].l=merge(r1,t[r2].l),update(r2),r2;
		}
	}
	pii split(int rt,int k){
		if(!k)return mp(0,rt);
		int l=t[rt].l,r=t[rt].r;
		if(k==t[l].size)return t[rt].l=0,update(rt),mp(l,rt);
		if(k==t[l].size+1)return t[rt].r=0,update(rt),mp(rt,r);
		if(k<t[l].size){
			pii tmp=split(l,k);
			return t[rt].l=tmp.second,update(rt),mp(tmp.first,rt);
		}
		pii tmp=split(r,k-t[l].size-1);
		return t[rt].r=tmp.first,update(rt),mp(rt,tmp.second);
	}
	int rank(int x,int k){
		int ans=0,tmp=INF;
		while(k){
			if(x==t[k].val)tmp=min(tmp,ans+t[t[k].l].size+1);
			if(x>t[k].val)ans+=t[t[k].l].size+1,k=t[k].r;
			else k=t[k].l;
		}
		return tmp==INF?ans:tmp;
	}
	int find(int x,int k){
    	while(1){
    	    if(t[t[k].l].size==x-1)return t[k].val;
    	    if(t[t[k].l].size>x-1)k=t[k].l;
    	    else x=x-t[t[k].l].size-1,k=t[k].r;
    	}
	}
	int pre(int x,int k){
	    int ans=-INF;
	    while(k){
	        if(t[k].val<x)ans=max(ans,t[k].val),k=t[k].r;
	        else k=t[k].l;
	    }
	    return ans;
	}
	int neg(int x,int k){
	    int ans=INF;
	    while(k){
	        if(t[k].val>x)ans=min(ans,t[k].val),k=t[k].l;
	        else k=t[k].r;
	    }
	    return ans;
	}
	void insert(int x){
		int k=rank(x,root);
		pii tmp=split(root,k);
		t[++num].val=x;
		t[num].key=rand();
		t[num].size=1;
		root=merge(tmp.first,num);
		root=merge(root,tmp.second);
	}
	void del(int x){
		int k=rank(x,root);
		pii t1=split(root,k);
		pii t2=split(t1.first,k-1);
		root=merge(t2.first,t1.second);
	}
}

//CDQ
namespace CDQ{
	Operator tmp[maxq];
	void do_main(Operator arr[],int l,int r){
		if(l>=r)return;
		int mid=l+r>>1;
		do_main(arr,l,mid);
		sort(arr+l,arr+mid+1,cmp1);sort(arr+mid+1,arr+r+1,cmp2);//Sort according to the partical order
		int x=l;
		for(int y=mid+1;y<=r;y++){
			while(x<=mid&&arr[x]<arr[y]){if(/*arr[x] is a modify operation*/)/*Change it*/;x++;}
			if(/*arr[y] is a query operation*/)/*Calculate the value*/;
		}
		for(int i=l;i<=mid;i++)if(/*arr[i] is a modify operation*/)/*Delete it*/;
		sort(arr+mid+1,arr+r+1,cmp3);//Sort according to the partical order
		do_main(arr,mid+1,r);
	}
}

//Eulerian Path
namespace Eulerian_Path{
	int q[maxm<<1],top=0;
	bool vis[maxm<<1];
	void dfs(int u){
		for(int &i=last[u];~i;i=e[i].nxt){
    		while(~i&&vis[i|1])i=e[i].nxt;
    		if(~i){
				vis[i|1]=1;
				dfs(e[i].v);
				q[++top]=i;
			}
		}
	}
}

//Suffix Array
namespace Suffix_Array{
	int cntA[300],cntB[300],sa[maxn],tsa[maxn],rank[maxn];
	void do_main(){
		memset(cntA,0,sizeof(cntA));
		for(int i=1;i<=n;i++)cntA[ch[i]]++;
		for(int i=1;i<256;i++)cntA[i]+=cntA[i-1];
		for(int i=n;i;i--)sa[cntA[ch[i]]--]=i;
		rank[sa[1]]=1;
		for(int i=2;i<=n;i++){
			rank[sa[i]]=rank[sa[i-1]];
			if(ch[sa[i]]!=ch[sa[i-1]])rank[sa[i]]++;
		}
		for(int l=1;rank[sa[n]]<n;l<<=1){
			memset(cntA,0,sizeof(cntA));
			memset(cntB,0,sizeof(cntB));
			for(int i=1;i<=n;i++){
				cntA[A[i]=rank[i]]++;
				cntB[B[i]=(i+l<=n)?rank[i+l]:0]++;
			}
			for(int i=1;i<=n;i++)cntA[i]+=cntA[i-1],cntB[i]+=cntB[i-1];
			for(int i=n;i;i--)tsa[cntB[B[i]]--]=i;
			for(int i=n;i;i--)sa[cntA[A[tsa[i]]]--]=tsa[i];
			rank[sa[1]]=1;
			for(int i=2;i<=n;i++){
				rank[sa[i]]=rank[sa[i-1]];
				if(A[sa[i]!=A[sa[i-1]]]||B[sa[i]!=B[sa[i-1]]])rank[sa[i]]++;
			}
		}
		for(int i=1,j=0;i<=n;i++){
			if(j)j--;
			while(ch[i+j]==ch[sa[rank[i]-1]+j)j++;
			height[rank[i]]=j;
		}
	}
}

//Gauss Elimination
namespace Gauss_Elimination{
	typedef double Matrix[maxn][maxn];
	bool do_main(Matrix A,int n){
		for(int i=0;i<n;i++){
			int r=i;
			for(int j=i+1;j<n;j++){
				if(fabs(A[j][i])>fabs(A[r][i]))r=j;
			}
			if(fabs(A[r][i])<eps)return 0;
			if(r!=i){
				for(int j=0;j<=n;j++)swap(A[r][j],A[i][j]);
			}
			for(int k=i+1;k<n;k++){
				double f=A[k][i]/A[i][i];
				for(int j=i;j<=n;j++)A[k][j]-=f*A[i][j];
			}
		}
		for(int i=n-1;i>=0;i--){
			for(int j=i+1;j<n;j++){
				A[i][n]-=A[j][n]*A[i][j];
			}
			A[i][n]/=A[i][i];
		}
		return 1;
	}
}

//Splay
namespace Splay{
	struct Node{
		int ch[2];
		int f,key,size,cnt,flip;
	}t[maxn];
	int sz,root;
	inline bool judge(int x){
		return t[t[x].f].ch[1]==x;
	}
	inline void update(int x){
		t[x].size=t[x].cnt+t[t[x].ch[0]].size+t[t[x].ch[1]].size;
	}
	inline void pushdown(int x){
    	if(t[x].flip){
			t[x].flip^=1;t[t[x].ch[0]].flip^=1;t[t[x].ch[1]].flip^=1;
			swap(t[x].ch[0],t[x].ch[1]);
		}
	}
	void rotate(int x){
		int f=t[x].f,ff=t[f].f;
		bool posx=judge(x),posf=judge(f);
		t[t[x].ch[posx^1]].f=f;t[f].ch[posx]=t[x].ch[posx^1];
		t[f].f=x;t[x].ch[posx^1]=f;
		t[x].f=ff;if(ff)t[ff].ch[posf]=x;
		update(f);update(x);
	}
	void splay(int x,int &tar){
		int tmp=t[tar].f;
		for(int i;(i=t[x].f)!=tmp;rotate(x)){
			if(t[i].f!=tmp)rotate(judge(x)==judge(i)?i:x);
		}
		tar=x;
	}
	void reset(int x,int f,int key){
		t[x].f=f;t[x].key=key;t[x].cnt=t[x].size=1;
	}
	void insert(int x){
		if(!root){reset(++sz,0,x);root=sz;return;}
		int now=root,f=0;
		while(1){
			if(x==t[now].key){t[now].cnt++;update(now);splay(now,root);return;}
			f=now;now=t[now].ch[t[now].key<x];
			if(!now){
				reset(++sz,f,x);
				t[f].ch[t[f].key<x]=sz;
				splay(sz,root);
				return;
			}
		}
	}
	int rank(int &rt,int x){
		int now=rt,res=1;
		while(now){
			pushdown(now);
			if(x==t[now].key){res+=t[t[now].ch[0]].size;splay(now,rt);return res;}
			else if(x>t[now].key)res+=t[now].size-t[t[now].ch[1]].size,now=t[now].ch[1];
			else now=t[now].ch[0];
		}
		return res;
	}
	int find(int &rt,int x){
		int now=rt,cnt=0;
		while(now){
			pushdown(now);
			if(cnt+t[now].size-t[t[now].ch[1]].size>=x&&cnt+t[t[now].ch[0]].size<x)return splay(now,rt),t[now].key;
			else if(cnt+t[now].size-t[t[now].ch[1]].size<x)cnt+=t[now].size-t[t[now].ch[1]].size,now=t[now].ch[1];
			else now=t[now].ch[0];
		}
		return splay(now,rt),t[now].key;
	}
	int merge(int &left,int right){
		if(!left||!right)return left|right;
		find(left,t[left].size);
		t[left].ch[1]=right;
		t[right].f=left;
		update(left);
		return left;
	}
	pii split(int &rt,int k){
		if(!k)return mp(0,rt);
		find(rt,k);
		int left=rt,right=t[rt].ch[1];
		t[left].ch[1]=0;
		t[right].f=0;
		update(left);
		return mp(left,right);
	}
	void del(int x){
		int k=rank(root,x);
		pii t1=split(root,k);
		pii t2=split(t1.first,k-1);
		if(!(--t[t2.second].cnt))root=merge(t2.first,t1.second);
		else{
			root=merge(t2.first,t2.second);
			root=merge(root,t1.second);
		}
	}
	int pre(int x){
        int res=-INF,now=root;
        while(now){
        	pushdown(now);
            if(t[now].key<x)res=max(res,t[now].key),now=t[now].ch[1];
            else now=t[now].ch[0];
		}
        return res;
    }
    int neg(int x){
        int res=INF,now=root;
        while(now){
        	pushdown(now);
            if(t[now].key>x)res=min(res,t[now].key),now=t[now].ch[0];
            else now=t[now].ch[1];
        }
        return res;
    }
    void reverse(int l,int r){
		pii p1=split(root,l-1);
		pii p2=split(p1.second,r-l+1);
		t[p2.first].flip^=1;
		root=merge(p2.first,p2.second);
		root=merge(p1.first,root);
	}
}

//Simulate Anneal
namespace Simulate_Anneal{
	const double eps=1e-9;
	bool accept(double delta,double temper){
		if(delta>=0)return 1;
		return rand()<exp(delta/temper)*RAND_MAX;
	}
    double f(State x){/* 对状态x进行估价，应该使估价值的数量级较大 */}
	double solve(){
		double t=/* 初始温度 */,del=0.999;
		State plan=/* 初始状态 */;
		while(t>eps){
			State newplan=/* 在plan状态的基础上根据t进行变动[ex:（一维坐标系下的模拟退火）double newplan=plan+(((double)rand()/RAND_MAX)*2-1)*t;] */;
			if(accept(f(newplan)-f(plan),t))plan=newplan;
			t*=del;
		}
		return f(plan);
	}
	double do_main(){
		srand(20010817);
		int res=INF;
		int T=100;//退火次数，可小一些
		while(T--){
			res=min(res,solve());
		}
		return res;
	}
}

//MFMC
namespace MFMC{
	int pe[maxn],dis[maxn];
	bool vis[maxn];
	namespace SPFA{
		bool do_main(int s,int t){
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));
			dis[s]=0;
			queue<int> q;
			vis[s]=1;
			q.push(s);
			while(!q.empty()){
				int u=q.front();q.pop();
				vis[u]=0;
				for(int i=last[u];~i;i=e[i].nxt){
					int v=e[i].v;
					if(e[i].f&&dis[v]>dis[u]+e[i].c){
						dis[v]=dis[u]+e[i].c;
						pe[v]=i;
						if(!vis[v]){
							vis[v]=1;
							q.push(v);
						}
					}
				}
			}
			return dis[t]<INF;
		}
	}
	pii do_main(int s,int t){
        memset(pe,-1,sizeof(pe));
		int cost=0,flow=0;
		while(SPFA::do_main(s,t)){
			int new_flow=INF;
			for(int i=pe[t];~i;i=pe[e[i].u])new_flow=min(new_flow,e[i].f);
			cost+=new_flow*dis[t];
			flow+=new_flow;
			for(int i=pe[t];~i;i=pe[e[i].u])e[i].f-=new_flow,e[i^1].f+=new_flow;
		}
		return pii(cost,flow);
	}
}

//Link-Cut Tree
namespace LCT{
	namespace Splay{
		struct Node{
			int ch[2];
			int f,key,size;
			bool rev;
			Node(){f=key=rev=size=0;}
		}t[maxn];
		int sz,root;
		inline bool judge(int x){
			return t[t[x].f].ch[1]==x;
		}
		inline void update(int x){
			t[x].size=1+t[t[x].ch[0]].size+t[t[x].ch[1]].size;
		}
		inline void pushdown(int x){
			if(t[x].rev){
				t[x].rev^=1;t[t[x].ch[0]].rev^=1;t[t[x].ch[1]].rev^=1;
				swap(t[x].ch[0],t[x].ch[1]);
			}
		}
		bool is_root(int x){
			return t[t[x].f].ch[0]!=x&&t[t[x].f].ch[1]!=x;
		}
		void rotate(int x){
			int f=t[x].f,ff=t[f].f;
			bool posx=judge(x),posf=judge(f);
			t[x].f=ff;if(!is_root(f))t[ff].ch[posf]=x;
			t[t[x].ch[posx^1]].f=f;t[f].ch[posx]=t[x].ch[posx^1];
			t[f].f=x;t[x].ch[posx^1]=f;
			update(f);update(x);
		}
		int sta[maxn];
		void splay(int x){
			int top=0;
			sta[++top]=x;
			for(int i=x;!is_root(i);i=t[i].f)sta[++top]=t[i].f;
			for(int i=top;i;i--)pushdown(sta[i]);
			for(int i;!is_root(x);rotate(x)){
				if(!is_root(i=t[x].f))rotate(judge(x)==judge(i)?i:x);
			}
		}
	}
	using namespace Splay;
	void access(int x){
		int tmp=0;
		while(x){
			splay(x);
			t[x].ch[1]=tmp;
			tmp=x;x=t[x].f;
		}
	}
	void mroot(int x){
		access(x);
		splay(x);
		t[x].rev^=1;
	}
	void link(int x,int y){
		mroot(x);
		t[x].f=y;
		splay(x);
	}
	void cut(int x,int y){
		mroot(x);
		access(y);
		splay(y);
		t[y].ch[0]=t[x].f=0;
	}
}

//Baby Steps Giant Steps
namespace BSGS{
	using namespace Quick_pow;
	map<int,int>mp;
	int do_main(int a,int b,int p){
		if(a%p==0)return -1;
		mp.clear();
		int m=ceil(sqrt(p));
		int am=Quick_Pow::do_main(a,m);
		int baj=b%p;
		mp[baj]=0;
		for(int j=1;j<=m;j++){
			baj=baj*a%p;
			mp[baj]=j;
		}
		int ami=1;
		for(int i=1;i<=m;i++){
			ami=ami*am%p;
			if(mp.count(ami))return i*m-mp[ami];
		}
		return -1;
	}
}

//Minimum Coverage Circle
namespace MCC{
	Point GetLineIntersection(Line l1,Line l2){return l1.p+l1.v*(Cross(l2.v,l1.p-l2.p)/Cross(l1.v,l2.v));}
	bool In_Circle(Point p,Circle c){return dcmp(Len(p-c.o)-c.r)<0;}
	Circle Cir(Point a){Circle C;C.o=a,C.r=0;return C;}
	Circle Cir(Point a,Point b){Circle C;C.o=(a+b)/2,C.r=Len(C.o-a);return C;}
	Circle Cir(Point a,Point b,Point c){
		Circle C;
		Line l1=(Line){(a+b)/2,Normal(a-b)},l2=(Line){(b+c)/2,Normal(b-c)};
		C.o=GetLineIntersection(l1,l2);
		C.r=Len(C.o-a);
		return C;
	}
	Circle do_main(Point *P,int n){
		random_shuffle(P+1,P+n+1);
		Circle c;
		for(int i=1;i<=n;i++){
			if(!In_Circle(P[i],c)){
				c=Cir(P[i]);
				for(int j=1;j<i;j++){
					if(!In_Circle(P[j],c)){
						c=Cir(P[i],P[j]);
						for(int k=1;k<j;k++){
							if(!In_Circle(P[k],c)){
								if(dcmp(Cross(P[i]-P[j],P[i]-P[k])))c=Cir(P[i],P[j],P[k]);
								else if(dcmp(Len(P[i]-P[k])-Len(P[j]-P[k]))>0)c=Cir(P[i],P[k]);
								else c=Cir(P[j],P[k]);
							}
						}
					}
				}
			}
		}
		return c;
	}
}

//Minimum Representation
namespace MR{
	int do_main(char* s){
		int i,j,k;
		for(i=1,j=2,k=0;i<=n&&j<=n&&k<=n;){
			int dif=s[i+k]-s[j+k];
			if(!dif)k++;
			else{
				if(dif>0)i=max(i+k+1,j+1);
				else j=max(j+k+1,i+1);
				k=0;
			}
		}
		return min(i,j);
	}
}

//Suffix Automaton
namespace SAM{
	struct Node{
		int min,max,trans[sigma_size],slink,endpos;
		LL cnt;
	}t[maxn<<1];
	int sz=1,ed=1;
	int degree[maxn<<1];
	bool is_pre[maxn<<1];
	inline int New_node(int minlen,int maxlen,int *trans,int slink){
		sz++;
		t[sz].min=minlen,t[sz].max=maxlen,t[sz].slink=slink;
		if(trans!=NULL)for(int i=0;i<sigma_size;i++)t[sz].trans[i]=trans[i];
		return sz;
	}
	void Insert(char ch){
		int c=ch-'a';
		int z=New_node(-1,t[ed].max+1,NULL,-1);
		is_pre[z]=1;
		int v=ed;
		ed=z;
		while(v&&!t[v].trans[c]){
			t[v].trans[c]=z;
			v=t[v].slink;
		}
		if(!v){
			t[z].min=1;
			t[z].slink=1;
			degree[1]++;
			return;
		}
		int x=t[v].trans[c];
		if(t[v].max+1==t[x].max){
			t[z].min=t[x].max+1;
			t[z].slink=x;
			degree[x]++;
			return;
		}
		int y=New_node(t[t[x].slink].max+1,t[v].max+1,t[x].trans,t[x].slink);
		t[x].slink=t[z].slink=y;degree[y]+=2;
		t[x].min=t[z].min=t[y].max+1;
		while(v&&t[v].trans[c]==x){
			t[v].trans[c]=y;
			v=t[v].slink;
		}
	}
	queue<int>q;
	void Topo(){
		for(int i=2;i<=sz;i++){
			if(!degree[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			if(is_pre[u])t[u].cnt++;
			t[t[u].slink].cnt+=t[u].cnt;
			if(--degree[t[u].slink]==0)q.push(t[u].slink);
		}
	}
}

//ConvexHull
namespace ConvexHull{
	Polygon do_main(Point p[],int n){
		sort(p+1,p+n+1);
		Polygon res;
		for(int i=1;i<=n;i++){
			while(res.num>1&&Cross(res.p[res.num]-res.p[res.num-1],p[i]-res.p[res.num-1])<=0)res.num--;
			res.p[++res.num]=p[i];
		}
		int tmp=res.num;
		for(int i=n-1;i;i--){
			while(res.num>tmp&&Cross(res.p[res.num]-res.p[res.num-1],p[i]-res.p[res.num-1])<=0)res.num--;
			res.p[++res.num]=p[i];
		}
		if(num>1)res.num--;
		return res;
	}
}

//Half-plane Intersection
namespace HPI{
	Polygon do_main(Line l[],int n){
		sort(l+1,l+n+1);
		int top=0;
		for(int i=1;i<=n;i++){
			if(i==1||l[i].ang!=l[i-1].ang)l[++top]=l[i];
		}
		int head=1,tail=0;
		q[++tail]=l[1];q[++tail]=l[2];
		for(int i=3;i<=top;i++){
			while(head<tail&&OnRight(Intersection(q[tail],q[tail-1]),l[i]))tail--;
			while(head<tail&&OnRight(Intersection(q[head],q[head+1]),l[i]))head++;
			q[++tail]=l[i];
		}
		while(head<tail&&OnRight(Intersection(q[tail],q[tail-1]),l[head]))tail--;
		while(head<tail&&OnRight(Intersection(q[head],q[head+1]),l[tail]))head++;
		Polygon res;
		q[tail+1]=q[head];
		for(int i=head;i<=tail;i++)res.p[++res.num]=Intersection(q[i],q[i+1]);
		return res;
	}
}

//Leftist Tree
namespace Leftist_Tree{
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	struct Node{
		int f,val,ch[2],h,size;
	}t[maxn];
	int Merge(int x,int y){
		if(!x||!y)return x+y;
		if(t[x].val<t[y].val)swap(x,y);
		rs=Merge(rs,y);
		t[rs].f=x;
		if(t[ls].size<t[rs].size)swap(ls,rs);
		t[x].size=t[ls].size+t[rs].size+1;
		t[x].h=t[rs].h+1;
		return x;
	}
	void Del(int x){
		t[x].val=0;
		t[ls].f=t[rs].f=0;
		Merge(ls,rs);
	}
}

namespace Faction_Segment_Tree{
	struct Node{
		int ls,rs,sum;
	}t[maxn*40];
	int sz=0;
	int Update(int pre,int l,int r,int x,int k){
		int now=++sz;
		t[now]=t[pre];t[now].sum+=k;
		if(l<r){
			int mid=l+r>>1;
			if(x<=mid)t[now].ls=Update(t[pre].ls,l,mid,x,k);
			else t[now].rs=Update(t[pre].rs,mid+1,r,x,k);
		}
		return now;
	}
	int Query(int L,int R,int l,int r,int k){
		if(l==r)return l;
		int del=t[t[R].ls].sum-t[t[L].ls].sum;
		int mid=l+r>>1;
		if(k<=del)return Query(t[L].ls,t[R].ls,l,mid,k);
		else return Query(t[L].rs,t[R].rs,mid+1,r,k-del);
	}
}