#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e9 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        if (l * 2 <= r) cout << l << " " << 2 * l << endl;
        else cout << -1 << " " << -1 << endl;
    }
}