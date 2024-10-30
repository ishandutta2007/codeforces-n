#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int ans[26];
string s, t;
vector<pair<char, char> > res;

int main() {
  ios::sync_with_stdio(false);
  cin >> s >> t;
  reset(ans, -1);
  int n = s.size();
  REP (i, n) {
    int x = s[i] - 'a';
    int y = t[i] - 'a';
    if (1) {
      if (ans[x] != -1 && ans[x] != y) {
        cout << -1;
        return 0;
      }
      if (ans[y] != -1 && ans[y] != x) {
        cout << -1;
        return 0;
      }
      if (ans[x] == y && ans[y] == x) continue;
      ans[x] = y;
      ans[y] = x;
      if (x != y) res.pb({(char)(x + 'a'), (char)(y + 'a')});
    }
  }
  cout << res.size() << endl;
  for (auto p: res) cout << p._1 << ' ' << p._2 << endl;
}