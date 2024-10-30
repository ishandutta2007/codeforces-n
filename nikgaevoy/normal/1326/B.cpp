#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> b(n);

	for (auto &it : b)
		cin >> it;

	vector<ll> pm(n + 1);

	for (int i = 0; i < n; i++)
	{
		auto a = b[i] + pm[i];

		cout << a << ' ';

		pm[i + 1] = max(pm[i], a);
	}

	cout << endl;
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