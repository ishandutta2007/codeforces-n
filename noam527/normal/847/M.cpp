#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, d, a[101];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	d = a[1] - a[0];
	for (int i = 2; i < n; i++) {
		if (a[i] - a[i - 1] != d) return cout << a[n - 1] << endl, 0;
	}
	cout << a[n - 1] + d << endl;
}