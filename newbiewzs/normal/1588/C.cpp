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
#include<cmath>
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
const int N=3e5+5;
int T,n,a[N],ans,tag,zs=0;
void kel(int x){
	if(ans==x){
		cout<<"nsdb";
	}
}
void kell(int x){
	if(a[1]==x){
		cout<<"nsdb";
	}
}
void solve(int n,int *a) {
	multiset<pll>s;
	map<int,int>tmp;
	tag=0;
	for(int i=1;i<=n;i+=2){
		s.insert(mp(-tag,i));
		tmp[-tag]++;
		tag+=a[i];
		kell(-564561);
		while(1){
			if(!s.empty() && (*s.begin()).fi+tag<0){
				tmp[(*s.begin()).fi]--;
				s.erase(s.begin());
			}
			else break;
		}
		ans+=tmp[-tag];
		kel(-561561);
		if(i==n)break;
		int j=i+1;
		tag-=a[j];
		while(1){
			if(s.size()!=0 && (*(--s.end())).fi+tag>0){
				tmp[(*(--s.end())).fi]--;
				s.erase(--s.end());
			}
			else break;
		}
		ans+=tmp[-tag];
	}
}
void solve2(){
	multiset<pll>s;
	map<int,int>tmp;
	tag=0;
	n--;
	for(int i=1;i<=n;i++)a[i]=a[i+1];
	for(int i=1;i<=n;i+=2){
		s.insert(mp(-tag,i));
		tmp[-tag]++;
		tag+=a[i];
		kell(-5616511);
		while(1){
			if(!s.empty() && (*s.begin()).fi+tag<0){
				tmp[(*s.begin()).fi]--;
				s.erase(s.begin());
			}
			else break;
		}
		ans+=tmp[-tag];
		if(i==n)break;
		int j=i+1;
		kel(-5645665);
		tag-=a[j];
		while(1){
			if(s.size()!=0 && (*(--s.end())).fi+tag>0){
				tmp[(*(--s.end())).fi]--;
				s.erase(--s.end());
			}
			else break;
		}
		ans+=tmp[-tag];
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		solve(n,a);
		if(n>1){
			solve2();
		}
		cout<<ans<<'\n';
	}
	return 0;
}