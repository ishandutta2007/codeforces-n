#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	#ifdef WIN
		#include<windows.h>
		int cnt=0;
		template<typename T>
		T debug(T x){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		  	cerr<<x<<" ";
		  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		template<typename T,typename ...Types>
		void debug(T x,Types ... y){
			cnt++;int tmp=cnt;
			debug(x);
			debug(y...);
			if(tmp==cnt)cerr<<'\n';
		}
	#else
		// Linux
		/*#define Green \033[32m
		#define Reset \033[0m\n
		void debug(int x){
			cout<<"Green"<<x<<"Reset";
		}*/
	#endif
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]=' ';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=1e6+5;
struct node{
	int l,k,id;
};
int T,n,m,M,deep,a[N],p[N],ans[N],tong[N],x,y,z;
vector<node>q[N];
vi v[N];
set<int>s[N];
int bit[(1<<20)+5];
void del(int x){
	for(;x<=M;x+=(x&(-x)))bit[x]--;
}
void add(int x){
	for(;x<=M;x+=(x&(-x)))bit[x]++;
}
int query(int x){
	int tmp=0;
	for(;x;x-=(x&(-x)))tmp+=bit[x];
	return tmp;
}
int ask(int x){
	int u=0;
	for(int i=deep;~i;i--){
		u+=(1<<i);
		if(u>=M || bit[u]>=x)u-=(1<<i);
		else x-=bit[u];
	}
	return u+1;
}
void dfs(int u){
	int tmp=tong[a[u]];
	if(tmp){
		s[tmp].erase(a[u]);
		del(tmp);
	}
	tong[a[u]]++;
	s[tong[a[u]]].insert(a[u]);
	add(tong[a[u]]);
	int tpp=query(n);
	for(auto i:q[u]){
		int pre=query(i.l-1);
		pre+=i.k;
		if(pre>tpp)ans[i.id]=-1;
		else ans[i.id]=ask(pre);
		if(ans[i.id]!=-1){
			ans[i.id]=*s[ans[i.id]].begin();
		}
	}
	for(auto i:v[u]){
		dfs(i);
	}
	s[tong[a[u]]].erase(a[u]);
	del(tong[a[u]]);
	tong[a[u]]--;
	if(tmp)s[tmp].insert(a[u]),add(tmp);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();M=1;deep=0;
		while(M<n)M*=2,deep++;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=2;i<=n;i++)p[i]=read(),v[p[i]].pb(i);
		for(int i=1;i<=m;i++){
			x=read();y=read();z=read();
			q[x].pb({y,z,i});
		}
		dfs(1);
		for(int i=1;i<=n;i++)q[i].clear(),v[i].clear();
		for(int i=1;i<=m;i++){
			print(ans[i]);
		}
		ss[++ssl]='\n';
	}
	Flush();
	return 0;
}