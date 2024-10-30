/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
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
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
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
/*
     -1,0   x   max(x-1,0)
   -inf,0 * 0  =         0

     +1,0   x   x+1
   -inf,0 * 0  =0

*/
struct mat{
	int a[2][2];
	int *operator [](int b){return a[b];}
	mat operator *(mat b){
		mat c;
		c[0][0]=max(a[0][0]+b[0][0],a[0][1]+b[1][0]);
		c[0][1]=max(a[0][0]+b[0][1],a[0][1]+b[1][1]);
		c[1][0]=max(a[1][0]+b[0][0],a[1][1]+b[1][0]);
		c[1][1]=max(a[1][0]+b[0][1],a[1][1]+b[1][1]);
		return c;
	}
};
mat b;
struct smt{
	mat sum;
	smt *l,*r;
	int ls,rs;
	smt(int la,int ra){
		ls=la;rs=ra;	
		if(ls==rs){
			l=r=0;
			sum[0][0]=0;sum[0][1]=0;
			sum[1][0]=-inf;sum[1][1]=0;
		}
		else{
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
			sum=r->sum*l->sum;
		}
	}
	void upd(int x,int y){
		if(ls==rs){sum[0][0]=y;return;}	
		if(x<=l->rs)l->upd(x,y);
		else r->upd(x,y);
		sum=r->sum*l->sum;
	}
};
smt *rt;
int p[300005],at[300005],q[300005];
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int n;
	read(n);
	rt=new smt(1,n+n);
	for(int i=1;i<=n;++i){
		read(p[i]);at[p[i]]=i;
	}
	for(int i=1;i<=n;++i)read(q[i]);
	int ans=n+1;
	for(int i=1;i<=n;++i){
		while(!((rt->sum*b)[0][0])){
			--ans;
			rt->upd((at[ans]<<1)-1,1);
		}
		write(ans,i==n?'\n':' ');
		rt->upd(q[i]<<1,-1);
	}
	return 0;
}