#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int h1, a1, c, h2, a2;

int main() {
	fast;
	cin >> h1 >> a1 >> c >> h2 >> a2;

	vector<string> ans;
	while (h2 > 0) {
		if (h1 > a2 || h2 <= a1) ans.push_back("STRIKE"), h2 -= a1;
		else ans.push_back("HEAL"), h1 += c;
		h1 -= a2;
	}
	cout << ans.size() << endl;
	for (auto &i : ans) cout << i << endl;
}