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
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

ll dp[112][112][112];
int c[112][112];
const ll INF=1e17;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m,t;
  cin>>n>>m>>t;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  rep(i,n) rep(j,m) cin>>c[i][j];
  fill(dp[0][0],dp[0][0]+112*112*112,INF);
  if(a[0]) dp[1][a[0]-1][1]=0;
  else rep(i,m) dp[1][i][1]=c[0][i];
  reps(i,1,n) rep(j,m) rep(k,t+1){
    rep(l,m) if(a[i]==0 || a[i]-1==l)
      MN(dp[i+1][l][k+(j!=l)],dp[i][j][k]+(a[i]?0:c[i][l]));
  }
  //rep(i,n+1){rep(j,m){rep(k,t+1)cout<<dp[i][j][k]<<",";cout<<endl;}cout<<endl;}
  ll re=INF;
  rep(i,m) MN(re,dp[n][i][t]);
  cout<<(re==INF?-1:re)<<endl;
  return 0;
}