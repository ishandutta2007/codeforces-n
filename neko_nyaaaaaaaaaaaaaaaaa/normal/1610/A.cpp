#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (n == 1 && m == 1) {
			cout << "0\n";
		} else if (n == 1 || m == 1) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}

	return 0;
}