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
//#define int long long
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
const int mod=1e9+7;
int n,a[N],maxx,tong[N*2],fac[N*2],summ[N*2],len;
int ans1=0,ans2=1;
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
int main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();fac[0]=1;
	for(int i=1;i<=n;i++)a[i]=read(),maxx=max(maxx,a[i]);
	for(int i=1;i<=n;i++)tong[a[i]]++;
	for(int i=1;i<=max(maxx,n);i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=maxx;i++)len=add(len,1ll*i*tong[i]%mod);
	int pre=0;
	for(int i=maxx;i>=1;i--){
		const int tmp=tong[i];
		if(i==1){
			ans2=1ll*ans2*fac[tmp]%mod;
			continue;
		}
		ans1=add(ans1,1ll*(i-1)*tmp%mod*(len-tmp)%mod);
		ans2=1ll*ans2*fac[tmp]%mod*fac[tmp]%mod;
		if(i>=2)tong[i-2]=add(tong[i-2],tong[i]);
		len=(len-tmp*2ll%mod+mod)%mod;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}