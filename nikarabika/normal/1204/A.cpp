//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	if (s == "0")
		return cout << 0 << endl, 0;
	for (int i = sz(s) - 1; i >= 0; i--) {
		if (s[i] == '1') {
			s[i] = '0';
			break;
		}
		else
			s[i] = 1;
	}
	int n = sz(s) - (s[0] == '0');
	cout << (n+1) / 2 << endl;
	return 0;
}