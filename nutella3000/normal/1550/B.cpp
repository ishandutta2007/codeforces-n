#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3;

void run() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) ++cnt;
    }
    cout << max(a * n + n * b, a * n + (cnt / 2 + 1) * b) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}