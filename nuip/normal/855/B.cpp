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
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	ll a,b,c;
	cin>>n>>a>>b>>c;
	vector<ll> vs(n);
	for(auto &x:vs) cin>>x;
	vector<pll> L(n); L[0]=pll(vs[0],vs[0]);
	reps(i,1,n){
		L[i]=L[i-1];
		MN(L[i].X,vs[i]);
		MX(L[i].Y,vs[i]);
	}
	vector<pll> R(n); R.back()=pll(vs.back(),vs.back());
	rreps(i,1,n){
		R[i-1]=R[i];
		MN(R[i-1].X,vs[i-1]);
		MX(R[i-1].Y,vs[i-1]);
	}
	ll re=-5e18;
	rep(i,n){
		auto l=L[i];
		auto r=R[i];
		MX(re,a*l.X+b*vs[i]+c*r.X);
		MX(re,a*l.X+b*vs[i]+c*r.Y);
		MX(re,a*l.Y+b*vs[i]+c*r.X);
		MX(re,a*l.Y+b*vs[i]+c*r.Y);
	}
	cout<<re NL;
  return 0;
}