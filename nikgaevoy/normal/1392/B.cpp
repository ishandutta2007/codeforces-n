#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	ll k;

	cin >> n >> k;

	if (k > 10)
	{
		k -= 10;
		k %= 2;

		k += 10;
	}

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	for (int i = 0; i < k; i++)
	{
		auto mx = *max_element(arr.begin(), arr.end());

		for (auto &it : arr)
			it = mx - it;
	}

	for (auto it : arr)
		cout << it << ' ';
	cout << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		solve_test(cin, cout);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}