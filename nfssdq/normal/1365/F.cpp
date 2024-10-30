// https://codeforces.com/contest/1359/problem/F
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        998244353ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int A[555], B[555];
vector < pair < int, int > > va, vb;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  FOR(ts, 1, T+1){
    int n; cin >> n;
    REP(i, n) cin >> A[i];
    REP(i, n) cin >> B[i];
    if(n % 2 == 1 && A[n/2] != B[n/2]){
      cout << "No" << endl;
      continue;
    }

    va.clear();
    vb.clear();
    
    for(int i = 0, j = n-1; i < j; i++, j--){
      int x = A[i], y = A[j];
      if(x > y) swap(x, y);
      va.pb(mp(x, y));
      x = B[i], y = B[j];
      if(x > y) swap(x, y);
      vb.pb(mp(x, y));
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    bool fl = true;
    REP(i, va.size()){
      if(va[i] != vb[i]) fl = false;
    }
    if(fl) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
}