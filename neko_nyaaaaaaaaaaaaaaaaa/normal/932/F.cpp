#include <bits/stdc++.h>
using namespace std;

typedef long long T;
const T oo = (T) 2e18;
struct Line {
	T a, b;
	Line(T a = 0, T b = 0) : a(a), b(b) {}
	int operator < (const Line& rhs) const {
		return make_pair(-a, b) < make_pair(-rhs.a, rhs.b);
	}
	int operator == (const Line& rhs) const {
		return make_pair(a, b) == make_pair(rhs.a, rhs.b);
	}
	int operator != (const Line& rhs) const {
		return make_pair(a, b) != make_pair(rhs.a, rhs.b);
	}
	T query(T x) {
		return a * x + b;
	}
};
struct CHT {
	long double intersect(Line ln1, Line ln2) {
		return (long double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
	}
	int bad(Line ln1, Line ln2, Line ln3) {
		return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
		//return intersect(ln1, ln2) >= intersect(ln2, ln3);
	}
	set<Line> hull;
	set<pair<long double, Line> > pos;
	void add(T a, T b) {
		Line ln(a, b);
		if (hull.find(ln) != hull.end()) return;
		hull.insert(ln);
		set<Line>::iterator it = hull.find(ln);
		if (it == hull.begin()) {
			pos.insert(make_pair(-oo, ln));
			if (++it != hull.end()) pos.erase(make_pair(-oo, *it));
			it--;
		}
		else {
			Line prv = *(--it); it++;
			if (prv.a == ln.a) {
				hull.erase(ln);
				return;
			}
			if (*it != *hull.rbegin()) {
				Line nxt = *(++it); it--;
				if (bad(prv, ln, nxt)) {
					hull.erase(ln);
					return;
				}
				pos.erase(make_pair(intersect(prv, nxt), nxt));
			}
		}
		Line u, v;
		if (it != hull.begin()) {
			v = *(--it);
			while (it != hull.begin()) {
				u = *(--it);
				if (bad(u, v, ln)) {
					pos.erase(make_pair(intersect(u, v), v));
					hull.erase(v); it = hull.find(v = u);
				}
				else {
					it++;
					break;
				}
			}
			pos.insert(make_pair(intersect(v, ln), ln));
			it++;
		}
		if (*it != *hull.rbegin()) {
			u = *(++it);
			while (*it != *hull.rbegin()) {
				v = *(++it);
				if (ln.a == u.a || bad(ln, u, v)) {
					pos.erase(make_pair(intersect(u, v), v));
					hull.erase(u); it = hull.find(u = v);
				}
				else {
					it--;
					break;
				}
			}
			pos.insert(make_pair(intersect(ln, u), u));
			it--;
		}
	}
	void add(Line ln) {
		add(ln.a, ln.b);
	}
	T query(T x) {
		if (!pos.size()) return oo;
		set<pair<long double, Line> >::iterator it = pos.upper_bound(make_pair(x, Line(-oo, -oo)));
		it--;
		return it->second.a * x + it->second.b;
	}
};

const int MAX = 100005;

int n;
vector<int> adj[MAX];
vector<int> a(MAX), b(MAX);
vector<long long> dp(MAX);

set<int> s;
CHT S; 

void solve(int now, int prev) {
	long long ans = 1e18;
	set<int> t; CHT T;

	for (auto u: adj[now]) {
		if (u != prev) {
			solve(u, now);

			if (s.size() > t.size()) {
				swap(s, t);
				swap(S, T);
			}

			for (int i: s) {
				t.insert(i);
				T.add(b[i], dp[i]);
			}
		}
	}

	if (!t.empty()) {
		dp[now] = T.query(a[now]);
	}

	t.insert(now);
	T.add(b[now], dp[now]);

	swap(s, t);
	swap(S, T);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve(1, 0);

	for (int i = 1; i <= n; i++) cout << dp[i] << ' ';

	return 0;
}