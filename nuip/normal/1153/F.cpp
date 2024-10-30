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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const deque<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class S, class T,class U,class V,class W> ostream& operator<<(ostream &os, const tuple<S,T,U,V,W> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<","<<get<4>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=998244353;
ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod=MOD> struct modInt{
  int v;
  modInt(int v=0):v(v){}
  modInt(ll v):v(v%MOD){}
  modInt operator+(const modInt &n)const{return v+n.v<mod ? v+n.v : v+n.v-mod;}
  modInt operator-(const modInt &n)const{return v-n.v<0 ? v-n.v+mod : v-n.v;}
  modInt operator*(const modInt &n)const{return ll(v)*n.v%mod;}
  modInt operator/(const modInt &n)const{return ll(v)*modpow(n.v%mod,-1,mod)%mod;}
  modInt operator+(const ll &n)const{return v+n<mod ? v+n : v+n-mod;}
  modInt operator-(const ll &n)const{return v-n<0 ? v-n+mod : v-n;}
  modInt operator*(const ll &n)const{return ll(v)*(n%mod)%mod;}
  modInt operator/(const ll &n)const{return ll(v)*modpow(n%mod,-1,mod)%mod;}
  modInt& operator+=(const modInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const modInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const modInt &n){v=ll(v)*n.v%mod; return *this;}
  modInt& operator/=(const modInt &n){v=ll(v)*modpow(n.v,-1,mod)%mod; return *this;}
  modInt& operator+=(const ll &n){v+=n; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const ll &n){v-=n; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  modInt& operator/=(const ll &n){v=ll(v)*modpow(n,-1,mod)%mod; return *this;}
};
#ifdef NUIP
class MINT_FRAC____{
public:
	unordered_map<int,pii> dict;
	MINT_FRAC____(int n){
		rep(p,n+1)reps(q,1,n+1)if(__gcd(p,q)==1){
			dict[1ll*p*modpow(q,-1)%MOD]=pii(p,q);
			dict[MOD-1ll*p*modpow(q,-1)%MOD]=pii(-p,q);
		}
	}
} Il1Il1Il1(1000);
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){if(Il1Il1Il1.dict.count(n.v)) os<<n.v<<"("<<Il1Il1Il1.dict[n.v].X<<"/"<<Il1Il1Il1.dict[n.v].Y<<")";else os<<n.v;return os;};
#else
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){return os<<n.v;};
#endif
template<int mod> modInt<mod> operator+(const ll &n,const modInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> modInt<mod> operator-(const ll &n,const modInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> modInt<mod> operator*(const ll &n,const modInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> modInt<mod> operator/(const ll &n,const modInt<mod> &m){return modInt<mod>(n%mod)/m;}
typedef modInt<MOD> mint;
template <int mod> modInt<mod> modpow(modInt<mod> r,ll n){ modInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class Doralion{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  Doralion(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} doralion(212345);

template<int B, int ROOT=3> // n <= 1<<B
struct FMT{
  mint R[2*(B+1)];
  vector<int> m2[(B+1)];
  vector<mint> power[2*(B+1)];
  FMT(){
    rep(e, (B+1)){
      m2[e].resize(1<<e);
      rep(m, 1<<e)rep(i,e) if(m&(1<<i)) m2[e][m] |= (1<<(e-1-i));
      
      mint w1 = modpow(ROOT,(MOD-1)/(2<<e));
      mint w2 = modpow(w1,-1);
      power[  e].resize(1<<e);
      power[(B+1)+e].resize(1<<e);
      power[e][0] = power[(B+1)+e][0] = 1;
      reps(j,1,(1<<e)){
				power[  e][j] = power[  e][j-1]*w1;
				power[(B+1)+e][j] = power[(B+1)+e][j-1]*w2;
      }
    }
  }
  
  void transform(mint *f, int N, bool inv){
    int e;
    for(e=0;;e++) if(N == (1<<e)) break;
    rep(m,N)if(m < m2[e][m]) swap(f[m], f[m2[e][m]]);
    for(int t=0,t2=1;t2<N;t++,t2+=t2){
      mint *po = power[inv*(B+1) + t].data();
      for(int i=0;i<N;i+=t2+t2){
				for (int j = 0; j < (1<<t); j++) {
					mint x = f[i+j];
					mint y = f[i+t2+j]*po[j];
					f[i+j] = x + y;
					f[i+t2+j] = x - y;
				}
      }
    }
    if(inv){
      mint ni=modpow(N,-1);
      for(int i = 0; i < N; i++) f[i] = f[i] * ni;
    }
  }
  template <typename T>
  vector<mint> convolution(const vector<T> &f, const vector<T> &g){
    const int n = f.size(), m = g.size();
    int n2 = 1;
    while(n2 < 2*max(f.size(), g.size())) n2 *= 2;
    vector<mint> cf(n2), cg(n2);
    rep(i, n) cf[i] = f[i];
    rep(i, m) cg[i] = g[i];
    transform(cf.data(), n2, false);
    transform(cg.data(), n2, false);
    rep(i, n2) cf[i] *= cg[i];
    transform(cf.data(), n2, true);
    return cf;
  }
};
FMT<12> fmt;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	// out(modpow(mint(2),(MOD-1)/2),1);
	// out(modpow(mint(3),(MOD-1)/2),1);
	// out(modpow(mint(5),(MOD-1)/2),1);
	int n,t,l;
	cin>>n>>t>>l;
	vector<mint> P(4096);
	vector<mint> nP(4096);
	P[2]=MOD-2; P[1]=2;
	nP[2]=2; nP[1]=MOD-2; nP[0]=1;
	fmt.transform(P.data(), 4096,false);
	fmt.transform(nP.data(), 4096,false);
	vector<mint> prod(4096);
	rep(i,4096) prod[i]=modpow(nP[i],n);
	// {
	// 	auto tmp=prod;
	// 	fmt.transform(tmp.data(), 4096, true);
	// 	rep(i,10) cout<<(mint)tmp[i]<<",";cout<<endl;
	// }
	mint re=0;
	vector<mint> r(4096);
	rep(j,4096) r[j]=P[j]/nP[j];
	reps(i,1,n+1){
		rep(j,4096){
			prod[j]*=r[j];
		}
		if(i<t) continue;
		auto tmp=prod;
		fmt.transform(tmp.data(), 4096, true);
		// rep(i,20) cout<<mint(tmp[i])<<",";cout<<endl;
		mint sum=0;
		rep(j,4096)	sum+=tmp[j]*inv[j+1];
		out(i,sum,1);
		sum*=comb(n,i);
		re+=sum;
	}
	cout<<re*l<<endl;
  return 0;
}
//TODO neg val -> upd