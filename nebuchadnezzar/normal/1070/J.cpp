#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	string s;
	cin >> s;
	vector<int> cnt(26);
	for (char c : s) {
		cnt[c - 'A']++;
	}

	vector<vector<bool>> d(27, vector<bool>(k + 1));

	d[0][0] = 1;

	for (int i = 0; i < 26; ++i) {
		for (int j = k - cnt[i]; j >= 0; --j) {
			for (int k = 0; k < 27; ++k) {
				if (d[k][j]) {
					d[k][j + cnt[i]] = true;
					d[i + 1][j + cnt[i]] = true;
				}
			}
		}
	}

	int ans = INF;

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (d[i + 1][j]) {
				if (j >= n) {
					int partm = max(0, m - (k - j));
					int partn = max(0, n - (j - cnt[i]));
					if (cnt[i] >= partm) {
						ans = min(ans, partn * partm);
					}
				}
			}
		}
	}

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}