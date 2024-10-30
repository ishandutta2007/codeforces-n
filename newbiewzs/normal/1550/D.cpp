#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
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
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
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
const int N=2e5+5;
const int M=2e5;
const int mod=1e9+7;
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int T,n,l,r,fac[N],ifac[N];
int C(int x,int y){
	if(x<y || x<0 || y<0)return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int work(int u){
	int x=max(u-(1-l),0ll);
	int y=max(u-(r-n),0ll);
	if(x+y>n)return 0;
	if(n&1){
		return (C(n-x-y,n/2-x)+C(n-x-y,n/2+1-x))%mod;
	}
	else{
		return C(n-x-y,n/2-x);
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	fac[0]=ifac[0]=1;
	for(int i=1;i<=M;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[M]=ksm(fac[M],mod-2);
	for(int i=M-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	while(T--){
		n=read();l=read();r=read();
		int tmp=min(1-l,r-n);
		int ans=1ll*tmp*C(n,n/2)%mod;
		if(n&1)ans=2ll*ans%mod;
		for(int i=tmp+1;i<=min(n-l,r-1);i++){
			ans=(ans+work(i))%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}