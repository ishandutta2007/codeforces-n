#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;

signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    int t;
    cin >> t;
    while(t--) {
    	int n, a, b, c, d;
    	cin >> n >> a >> b >> c >> d;
    	if ((a - b) * n <= c + d && (a + b) * n >= c - d) cout << "Yes";
    	else cout << "No";
    	cout << endl;
    }
}