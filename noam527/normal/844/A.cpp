#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

string s;
int k;
set<char> lol;

int main() {
	fast;
	cin >> s >> k;
	if (k > s.size()) {
		cout << "impossible" << endl;
		return 0;
	}
	for (auto i : s) lol.insert(i);
	cout << max(0, k - (int)lol.size()) << endl;
}