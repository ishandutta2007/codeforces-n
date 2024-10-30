/*
Author: QAQAutoMaton
Lang: C++
Code: D.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
	}
}__INIT___;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	template<typename A>
	inline bool read (A &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		while((x=gc())==' '||x=='\n' || x=='\r');
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	template<typename A>
	inline bool write (A x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
bitset<5005> ok[5005];
vector<pii> vt[5005];
int t[5005],x[5005];
bitset<5005>xok;
int mx[5005];
int dis(pii a,int b){
	return a.x<=b && b<=a.y?0:min(abs(a.x-b),abs(a.y-b));
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n;	
	read(n);
	for(int i=1;i<=n;++i){
		read(t[i],x[i]);
	}
	for(int i=n;i;--i)t[i]-=t[i-1];
	ok[0][0]=1;
	for(int i=1;i<=n;++i)if(x[i]==0)ok[0][i]=1;
	for(int i=0;i<n;++i){
		if(ok[i][0]){
			for(int j=i+2;j<=n;++j){
				if(abs(x[i]-x[j])+abs(x[j]-x[i+1])<=t[i+1]){
					ok[i+1][j]=1;	
				}	
			}
			//i+1,i+1?
			if(abs(x[i]-x[i+1])<=t[i+1]){
				ok[i+1][0]=1;
				xok[i+1]=1;
				chkmax(mx[i+1],t[i+1]-abs(x[i]-x[i+1]));
			}
		}
		for(int j=i+2;j<=n;++j)if(ok[i][j] && abs(x[i]-x[i+1])<=t[i+1]){
			ok[i+1][j]=1;
		}
		if(i && ok[i][i]){
			for(int j=i+2;j<=n;++j){
				for(auto seg:vt[i])if(dis(seg,x[j])+abs(x[j]-x[i+1])<=t[i+1])ok[i+1][j]=1;
			}
			int d=inf;
			for(auto seg:vt[i])chkmin(d,dis(seg,x[i+1]));
			if(d<=t[i+1]){
				ok[i+1][0]=1;
				xok[i+1]=1;
				chkmax(mx[i+1],t[i+1]-d);
			}
		}
		if(ok[i][i+1]){
			ok[i+1][i+1]=1;
			vt[i+1].emplace_back(x[i]-t[i+1],x[i]+t[i+1]);
		}
		if(xok[i+1]){
			vt[i+1].emplace_back(x[i+1]-mx[i+1],x[i+1]+mx[i+1]);
			ok[i+1][i+1]=1;
		}
	}
	write((ok[n][n] || ok[n][0])?"YES\n":"NO\n");
	return 0;
}