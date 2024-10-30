#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;

void run() {
    int n; cin >> n;
    vector<int> a(n), L(n), R(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int res = 0, tilt = 0;
    for (int i = 0; i < n-1; ++i) {
        a[i+1] -= tilt;
        
        res += abs(a[i] - a[i+1]);
        if (a[i+1] > a[i]) tilt += a[i+1] - a[i];

        a[i+1] = min(a[i], a[i+1]);
    }
    cout << res + abs(a[n-1]) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}