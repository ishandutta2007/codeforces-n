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
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
// #pragma GCC optimize(3)
//#define int long long
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
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
/*namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;*/
const int N=20;
int T,l,r,a[1<<18];
int ch[N*132000][2],siz[N*132000],tot,rt;
void insert(int &u,int deep,int x){
	if(!u)u=++tot;
	if(deep==0){
		siz[u]++;return;
	}
	insert(ch[u][(x&(1<<deep-1))>0],deep-1,x);
	siz[u]=siz[ch[u][0]]+siz[ch[u][1]];
}
#define ls ch[u][0]
#define rs ch[u][1]
int query(int u,int deep,int x,int k){
	if(!u)return 0;
	if(deep==0)return siz[u];
	int base=(1<<(deep-1));
	if((x&base) && (k&base)){
		return siz[rs]+query(ls,deep-1,x,k);
	}
	if((x&base) && !(k&base)){
		return query(rs,deep-1,x,k);
	}
	if(!(x&base) && (k&base)){
		return siz[ls]+query(rs,deep-1,x,k);
	}
	if(!(x&base) && !(k&base)){
		return query(ls,deep-1,x,k);
	}
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		l=read();r=read();
		for(int i=l;i<=r;i++)a[i]=read();
		for(int i=l;i<=r;i++){
			insert(rt,17,a[i]);
		}
		int ans=0;
		for(int i=l;i<=r;i++){
			if(l==0){
				if(query(rt,17,(a[i]^l),r)==r-l+1){
					ans=(a[i]^l);
					break;
				}
			}
			else{
				if(query(rt,17,(a[i]^l),l-1)==0 && query(rt,17,(a[i]^l),r)==r-l+1){
					ans=(a[i]^l);
					break;
				}
			}
		}
		cout<<ans<<'\n';
		#ifdef newbiewzs
			for(int i=l;i<=r;i++){
				cerr<<(a[i]^ans)<<" ";
			}
			cerr<<'\n';
		#endif
		for(int i=1;i<=tot;i++){
			ch[i][0]=ch[i][1]=siz[i]=0;
		}
		tot=rt=0;
	}
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}