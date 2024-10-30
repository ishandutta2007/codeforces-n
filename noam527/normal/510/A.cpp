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
const int md = 998244353;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m;

int main() {
	fast;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m, '.'));
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (i & 2) a[i][0] = '#';
			else a[i][m - 1] = '#';
		}
		else
			for (int j = 0; j < m; j++) a[i][j] = '#';
	}
	for (auto &i : a) {
		for (auto &j : i) cout << j;
		cout << endl;
	}
}