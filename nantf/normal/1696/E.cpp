#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=1e9+7;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,a[maxn],fac[maxn],ifac[maxn];
inline int C(int n,int m){
	if(n<0 || n<m || m<0) return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	n=read();
	FOR(i,0,n) a[i]=read();
	m=n+a[0];
	fac[0]=1;
	FOR(i,1,m) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[m]=qpow(fac[m],mod-2);
	ROF(i,m-1,0) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	int ans=0;
	FOR(i,0,n) ans=(ans+C(i+a[i],i+1))%mod;
	printf("%d\n",ans);
}