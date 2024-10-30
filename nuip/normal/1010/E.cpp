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

const int nn=112345;
int bit[nn+1];

int minf(int i){++i; //
  int s=MOD;
  while(i>0){
    s=min(s,bit[i]);
    i-=i&-i;
  }return s;
}
void upd(int i,int val){++i; //
  while(i<=nn){
    bit[i]=min(bit[i],val);
    i+=i&-i;
  }
  return;
}



int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int xm,ym,zm,n,m,q;
	cin>>xm>>ym>>zm>>n>>m>>q;
	int x=xm,y=ym,z=zm,X=0,Y=0,Z=0;
	rep(_,n){
		int a,b,c;
		cin>>a>>b>>c;
		MX(X,a); MX(Y,b); MX(Z,c);
		MN(x,a); MN(y,b); MN(z,c);
	}
	using TP=tuple<int,int,int,int>;
	vector<TP> tps(m+q);
	for(auto &tp:tps) cin>>get<0>(tp)>>get<1>(tp)>>get<2>(tp);
	rep(i,m) get<3>(tps[i])=-1;
	reps(i,m,m+q) get<3>(tps[i])=i-m;
	vector<int> re(q);
	for(auto tp:tps){
		int a,b,c,i;
		tie(a,b,c,i)=tp;
		if(x<=a && a<=X &&
			 y<=b && b<=Y &&
			 z<=c && c<=Z){
			if(i<0){
				cout<<"INCORRECT" NL;
				exit(0);
			}else{
				re[i]=1;
			}
		}
	}
	rep(_,2){
		rep(_,2){
			rep(_,2){
				sort(all(tps));
				fill(bit,bit+nn+1,MOD);
				for(auto tp:tps){
					int a,b,c,i;
					tie(a,b,c,i)=tp;
					if(a<x) continue;
					if(b<y) continue;
					if(c<z) continue;
					if(i<0){
						upd(b,c);
					}else if(re[i]==0){
						if(minf(b)<=c) re[i]=2;
					}
				}
				out(tps,re,x,X,y,Y,z,Z,1);
				for(auto &tp:tps) get<2>(tp)=zm+1-get<2>(tp);
				tie(z,Z)=pii(zm+1-Z,zm+1-z);
			}
			for(auto &tp:tps) get<1>(tp)=ym+1-get<1>(tp);
			tie(y,Y)=pii(ym+1-Y,ym+1-y);
		}
		for(auto &tp:tps) get<0>(tp)=xm+1-get<0>(tp);
		tie(x,X)=pii(xm+1-X,xm+1-x);
	}
	out(re,1);
	cout<<"CORRECT" NL;
	vector<string> strs{"UNKNOWN",
											"OPEN",
											"CLOSED"};

	for(int i:re) cout<<strs[i] NL;
	return 0;
}