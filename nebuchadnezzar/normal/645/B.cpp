#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &k);
	ll ans = 0;

	for (int i = 0; i < min(n / 2, k); ++i) {
	 	ans += 2 * (n - i * 2 - 1) - 1;
	}

	cout << ans << "\n";

	return 0;
}