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

int q, x;
set<int> s;

int main() {
	fast;
	for (int i = 0; i < 21; i++) {
		int t = i;
		if (t % 3 == 0 || t % 7 == 0) s.insert(i);
		while (t > 0) {
			t -= 3;
			if (t % 7 == 0) s.insert(i);
		}
	}

	cin >> q;
	while (q--) {
		cin >> x;
		if (x >= 21 || s.find(x) != s.end()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}