#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<random>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return move(re);}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
#define TT cauto TTT=read();rep(_,TTT)
const ll MOD=1e9+7; //998244353;

ll modpow_(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod=MOD> struct ModInt{
  int v;
  ModInt(int v=0):v(v){}
  ModInt operator+(const ModInt &n)const{return v+n.v<mod ? v+n.v : v+n.v-mod;}
  ModInt operator-(const ModInt &n)const{return v-n.v<0 ? v-n.v+mod : v-n.v;}
  ModInt operator*(const ModInt &n)const{return ll(v)*n.v%mod;}
  ModInt operator/(const ModInt &n)const{return ll(v)*modpow_(n.v%mod,-1,mod)%mod;}
  ModInt operator+(const ll &n)const{return v+n<mod ? v+n : v+n-mod;}
  ModInt operator-(const ll &n)const{return v-n<0 ? v-n+mod : v-n;}
  ModInt operator*(const ll &n)const{return ll(v)*(n%mod)%mod;}
  ModInt operator/(const ll &n)const{return ll(v)*modpow_(n%mod,-1,mod)%mod;}
  ModInt& operator+=(const ModInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const ModInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ModInt &n){v=ll(v)*n.v%mod; return *this;}
  ModInt& operator/=(const ModInt &n){v=ll(v)*modpow_(n.v,-1,mod)%mod; return *this;}
  ModInt& operator+=(const ll &n){v+=n; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const ll &n){v-=n; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  ModInt& operator/=(const ll &n){v=ll(v)*modpow_(n,-1,mod)%mod; return *this;}
	bool operator==(const ModInt &n)const{return v==n.v;};
	bool operator!=(const ModInt &n)const{return v!=n.v;};
	ModInt& operator++(){ return operator+=(1); }
	ModInt& operator--(){ return operator-=(1); }
	ModInt operator++(int i){ ModInt tmp(*this); operator++(); return tmp; }
	ModInt operator--(int i){ ModInt tmp(*this); operator--(); return tmp; }
};
#ifdef NUIP
class MINT_FRAC____{
public:
	unordered_map<int,pii> dict;
	MINT_FRAC____(int n){
		rep(p,n+1)reps(q,1,n+1)if(__gcd(p,q)==1){
			dict[1ll*p*modpow_(q,-1)%MOD]=pii(p,q);
			dict[MOD-1ll*p*modpow_(q,-1)%MOD]=pii(-p,q);
		}
	}
} Il1Il1Il1(1000);
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){if(Il1Il1Il1.dict.count(n.v)) os<<n.v<<"("<<Il1Il1Il1.dict[n.v].X<<"/"<<Il1Il1Il1.dict[n.v].Y<<")";else os<<n.v;return os;};
#else
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){return os<<n.v;};
#endif
template<int mod> ModInt<mod> operator+(const ll &n,const ModInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> ModInt<mod> operator-(const ll &n,const ModInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> ModInt<mod> operator*(const ll &n,const ModInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> ModInt<mod> operator/(const ll &n,const ModInt<mod> &m){return ModInt<mod>(n%mod)/m;}
typedef ModInt<MOD> mint;
template <int mod> ModInt<mod> modpow(ModInt<mod> r,ll n){ ModInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class Doralion{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  Doralion(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} doralion(1123456);
using pmm=pair<mint,mint>;
mint modpow(ll r,ll n){ return modpow_(r,n);}


int suf[20][1123456];
int pre[20][1123456];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	read();
	cauto q=read();
	cauto s0=read<string>();
	cauto t=read<string>();
	cauto qs=readV<pair<int,string>>(q);
	vector<int> inds(q); iota(all(inds),0);
	sort(all(inds),[&](cauto &i,cauto &j){ return qs[i].X<qs[j].X;});
	vector<mint> res(q);
	int curm=0;
	vector<mint> weis(26);
	for(cauto ind:inds){
		cauto &[m,s]=qs[ind];
		for(;curm<m;++curm){
			if(curm<20) continue;
			for(auto &w:weis) w+=w;
			weis[t[curm]-'a']+=1;
		}
		cauto n=(int)s.size();
		fill(suf[0],suf[0]+n,0);
		fill(pre[0],pre[0]+n,0);
		rep(i,n){
			for(auto &j=suf[0][i];j<(int)s0.size() && i+j<n && s0[j]==s[i+j]; ++j);
			for(auto &j=pre[0][i];j<(int)s0.size() && i-j>=0 && s0[s0.size()-1-j]==s[i-j]; ++j);
		}
		// rep(i,n) cout<<suf[0][i]<<","; cout NL;
		// rep(i,n) cout<<pre[0][i]<<","; cout NL;
		vector<ll> lens(20); lens[0]=s0.size();
		reps(i,1,20) lens[i]=lens[i-1]*2+1;
		out(lens,1);
		rep(k,19)rep(i,n){
			auto &j=suf[k+1][i];
			j=suf[k][i];
			if(j==lens[k] && i+j<n && s[i+j]==t[k]){
				++j;
				if(i+j<n) j+=suf[k][i+j];
			}
		}
		rep(k,19)rep(i,n){
			auto &j=pre[k+1][i];
			j=pre[k][i];
			if(j==lens[k] && i-j>=0 && s[i-j]==t[k]){
				++j;
				if(i-j>=0) j+=pre[k][i-j];
			}
		}
		out(s,1);
		// rep(k,20){rep(i,n) cout<<suf[k][i]<<","; cout NL;} cout NL;
		// rep(k,20){rep(i,n) cout<<pre[k][i]<<","; cout NL;} cout NL;
		mint &re=res[ind];
		mint pw=modpow(2,m);
		reps(i,n-1,s0.size()){
			int ok=1;
			rep(j,n)if(s0[i-j]!=s[n-1-j]){ ok=0; break;}
			if(ok) re+=pw;
		}
		out(re,1);
		rep(k,20){
			pw*=inv[2];
			if(k>=m) break;
			rep(i,n)if(s[i]==t[k] &&
								 (i==0 || pre[k][i-1]==i) &&
								 (i==n-1 || suf[k][i+1]==n-i-1)) re+=pw;
			// out(k,pw,re,1);
			// rep(i,n) out(i,s[i],t[k],pre[k][i],suf[k][i],1);
		}
		rep(i,n)if((i==0 || pre[19][i-1]==i) &&
							 (i==n-1 || suf[19][i+1]==n-i-1)) re+=weis[s[i]-'a'];

	}
	out(res,1);
	rep(i,res.size())rep(j,300)if(modpow(2,j)-1==res[i]) out(i,res[i],j,1);
	out(modpow(2,102)-1,1);
	for(cauto &re:res) cout<<re NL;
  return 0;
}