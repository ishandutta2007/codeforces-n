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
#define mod        1000000007ll
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

vector < vector < int > > vc;
bool done[1111];
int res[1111];

int go(int l, int r, int mx) {
  if(l == r) return l;
  int mid = (l + r) / 2;
  vector < int > tmp;
  REP(i, vc.size()){
    if(i < l || i > mid) continue;
    REP(j, vc[i].size()) tmp.pb(vc[i][j]);
  }

  cout << "? " << tmp.size();
  REP(i, tmp.size()) cout << " " << tmp[i];
  cout << endl;
  fflush(stdout);

  int nmx; cin >> nmx;
  if(nmx == mx){
    for(int i = mid + 1; i <= r; i++) res[i] = mx;
    return go(l, mid, mx);
  } else {
    for(int i = l; i <= mid; i++) res[i] = mx;
    return go(mid + 1, r, mx);
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  FOR(ts, 1, T+1){
    vc.clear();
    set0(done);
    int n, k; cin >> n >> k;
    REP(i, k){
      int sz; cin >> sz;
      vector < int > tmp;
      REP(j, sz){
        int x; cin >> x;
        done[x] = true;
        tmp.pb(x);
      }
      vc.pb(tmp);
    }
    vector < int > tmp;
    FOR(i, 1, n+1) if(!done[i]) tmp.pb(i);
    if(tmp.size() > 0) vc.pb(tmp);

    cout << "? " << n;
    REP(i, n) cout << " " << i+1;
    cout << endl;
    fflush(stdout);

    int mx; cin >> mx;
    int t = go(0, vc.size() - 1, mx);
    cout << "? " << n - vc[t].size();
    REP(i, vc.size()) if(i != t) REP(j, vc[i].size()) cout << " " << vc[i][j];
    cout << endl;
    fflush(stdout);
    cin >> res[t];

    cout << "!";
    REP(i, k) cout << " " << res[i];
    cout << endl;
    string s; cin >> s;
  }
}