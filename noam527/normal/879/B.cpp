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

int n, mx = 0, a[500], c[500] = {};
ll k;

int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		if (a[mx] < a[i]) mx = i;
		if (++c[mx] == k) finish(a[mx]);
	}
	finish(n);
}