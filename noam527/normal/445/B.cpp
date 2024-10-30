#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
ll ans = 1;

int dfs(int v) {
	int rtn = 1;
	vis[v] = 1;
	for (auto &i : g[v])
		if (!vis[i])
			rtn += dfs(i);
	return rtn;
}

int main() {
	fast;
	cin >> n >> m;
	g.resize(n), vis.resize(n, 0);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v), g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			int rtn = dfs(i);
			while (--rtn) ans *= 2;
		}
	}
	cout << ans << endl;
}