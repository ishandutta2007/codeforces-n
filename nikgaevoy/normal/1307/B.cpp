#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, x;

	cin >> n >> x;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	sort(arr.begin(), arr.end());

	if (binary_search(arr.begin(), arr.end(), x))
	{
		cout << 1 << endl;

		return;
	}

	cout << max(2, (x + arr.back() - 1) / arr.back()) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}