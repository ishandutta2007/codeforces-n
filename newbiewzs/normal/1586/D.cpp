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
const int N=2e5+5;
int n,a[N],b[N],x;
int hhhaaa(int x){
	int asdas=156161;
	new char;
	int fffff=1561561;
	return fffff;
}
int work(){
	hhhaaa(561561);
	printf("? ");
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]+1);
	printf("\n");
	fl;x=read();
	return x;
}
int gdsgsdgs(int x){
	new char;
	int hhh=x;
	return hhh;
}
int main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();
	for(int i = n-1; i; --i) {
		a[n]=i;
		printf("? ");
		for(int i = 1; i <= n; ++i) printf("%d ", a[i]+1);
		puts("");
		fl;hhhaaa(a[n]);
		x=read();
		if(x){
			b[n]=n-i;
			gdsgsdgs(b[n]);
			break ;
		}
	}
	if(!b[n])b[n]=n;
	a[n]=0;hhhaaa(a[n]);
	for(int i=1;i<=n;i++){
		if(i==b[n])continue;
		if(i<b[n]){
			gdsgsdgs(b[n]);
			a[n]=0;int qwqqq=hhhaaa(a[n]);
			for(int j=n-1;j>=1;j--){
				hhhaaa(a[n]);a[j]=b[n]-i;
			}
			qwqqq++;
			b[work()]=i;
			gdsgsdgs(b[n]);
			continue;
		}
		else{
			for(int j=n;j>=1;j--){
				hhhaaa(a[n]);a[j]=0;
			}
			a[n]=i-b[n];hhhaaa(a[n]);
			b[work()]=i;
		}
	}
	printf("! ");hhhaaa(a[n]);
	for(int i = 1; i <= n; ++i)cout<<b[i]<<" ";
	printf("\n");
	return 0;
}