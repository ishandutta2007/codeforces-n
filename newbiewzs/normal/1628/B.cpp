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
#define cpy(x,y) memcpy(x,y,sizeof(x))
//#pragma GCC optimize(3)
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
const int N=1e5+5;
int T,n,l[N],a[N][4];
char c[N][4];
int pd[27][27][27],pa[27][27];
int bj[27][27],tong[27],tc[27][27][27];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			scanf("%s",c[i]+1);
			l[i]=strlen(c[i]+1);
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(l[i]==1){
				flag=1;
				puts("YES");
				break;
			}
		}
		if(flag)continue;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=l[i];k++)a[i][k]=c[i][k]-'a';
			if(l[i]==2){
				bj[c[i][1]-'a'][c[i][2]-'a']=i;
			}
			else{
				pd[c[i][1]-'a'][c[i][2]-'a'][c[i][3]-'a']=i;
				pa[a[i][3]][a[i][2]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(l[i]==3){
				if(bj[a[i][2]][a[i][1]]>i)flag=1;
				if(pd[a[i][3]][a[i][2]][a[i][1]]>i)flag=1;
				if(a[i][1]==a[i][3])flag=1;
			}
			else{
				if(pa[a[i][1]][a[i][2]]>i)flag=1;
				if(bj[a[i][2]][a[i][1]]>i)flag=1;
				if(a[i][1]==a[i][2])flag=1;
			}
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
		memset(bj,0,sizeof(bj));
		memset(pd,0,sizeof(pd));
		memset(pa,0,sizeof(pa));
	}
	return 0;
}