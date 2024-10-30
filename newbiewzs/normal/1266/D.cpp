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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
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
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
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
const int N=3e5+5;
int n,m,x[N],y[N],z[N];
int in[N],ou[N],v[N],tmp[N];
vi a,b;
int sx[N],sy[N],sz[N],top;
void add(int x,int y,int z){
	sx[++top]=y;
	sy[top]=x;
	sz[top]=z;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x[i]=read();y[i]=read();z[i]=read();
		in[y[i]]+=z[i];
		ou[x[i]]+=z[i];
	}
	for(int i=1;i<=n;i++){
		v[i]=ou[i]-in[i];
		if(v[i]<0)a.pb(i);
		if(v[i]>0)b.pb(i);
	}
	for(auto i:a){
		while(b.size()){
			auto k=b.back();
			int tmp=min(abs(v[i]),abs(v[k]));
			add(i,k,tmp);
			v[i]+=tmp;
			v[k]-=tmp;
			if(!v[i])break;
			if(!v[k])b.pop_back();
		}
	}
	cout<<top<<'\n';
	for(int i=1;i<=top;i++){
		cout<<sx[i]<<" "<<sy[i]<<" "<<sz[i]<<'\n';
	}
	return 0;
}