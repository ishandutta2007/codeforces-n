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
const int N=5e5+5;
const int mod=998244353;
int T,n,a[N];
int add(int x,int y){
	return (x+y>=mod?x+y-mod:x+y);
}
int f[N][2];
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		
		for(int i=1;i<=n;i++){
			if(!a[i]){
				f[1][1]=2ll*f[1][1]%mod;
				f[0][0]=2ll*f[0][0]%mod;
				f[0][0]++;
			}
			else{
				f[a[i]-1][1]=2ll*f[a[i]-1][1]%mod;
				f[a[i]+1][1]=2ll*f[a[i]+1][1]%mod;
				f[a[i]][0]=2ll*f[a[i]][0]%mod;
				f[a[i]][0]=add(f[a[i]][0],f[a[i]-1][0]);
				if(a[i]==1)f[0][1]++;
				else f[a[i]-1][1]=add(f[a[i]-1][1],f[a[i]-2][0]);
				
			}
		}
		int ans=0;
		for(int i=0;i<=n;i++)ans=add(ans,add(f[i][0],f[i][1]));
		for(int i=0;i<=n+1;i++)f[i][0]=f[i][1]=0;
		cout<<ans<<'\n';
	}
	return 0;
}