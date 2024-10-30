// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> graph(n * 2);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		graph[a].push_back({b, w});
		graph[b + n].push_back({a + n, w});
	}

	for (int i = 0; i < n; ++i) {
		graph[i].push_back({i + n, 0});
	}

	vector<ll> dist(n * 2, INFL);
	dist[0] = 0;
	set<pair<ll, int>> st;
	st.insert({0, 0});
	while (szof(st)) {
		int v = st.begin()->ss;
		st.erase(st.begin());
		for (auto to : graph[v]) {
			if (dist[to.ff] > dist[v] + to.ss) {
				st.erase({dist[to.ff], to.ff});
				dist[to.ff] = dist[v] + to.ss;
				st.insert({dist[to.ff], to.ff});
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		if (dist[i + n] == INFL) {
			cout << "-1 ";
		} else {
			cout << dist[i + n] << " ";
		}
	}
	cout << "\n";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}