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

int n;
int a[max_n];

bool good(int l, int r) {
    for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
            for (int k = j + 1; k < r; ++k) {
                if (a[i] <= a[j] && a[j] <= a[k]) return false;
                if (a[i] >= a[j] && a[j] >= a[k]) return false;
            }
        }
    }
    return true;
}

void run() {
    pii a, b, f;
    cin >> a.fi >> a.se >> b.fi >> b.se >> f.fi >> f.se;
    int res = abs(a.fi - b.fi) + abs(a.se - b.se);

    auto func = [&]() {
        if (a.fi != b.fi || b.fi != f.fi) return false;
        return min(a.se, b.se) <= f.se && max(a.se, b.se) > f.se;
    };

    if (func()) res += 2;
    swap(a.fi, a.se); swap(b.fi, b.se); swap(f.fi, f.se);
    if (func()) res += 2;

    cout << res << endl;
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