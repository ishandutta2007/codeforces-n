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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[100001], mx = -1, c = 1, p;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p, a[p - 1] = i;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) c++;
		else mx = max(mx, c), c = 1;
	}
	mx = max(mx, c);
	cout << n - mx << endl;
}