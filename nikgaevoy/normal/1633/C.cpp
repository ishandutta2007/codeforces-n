#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll hc, dc, hm, dm;

	cin >> hc >> dc >> hm >> dm;

	ll k, w, a;

	cin >> k >> w >> a;

	auto check = [=](__int128 h, __int128 d)
	{
		auto turns = (h + dm - 1) / dm;

		return turns * (__int128) d >= hm;
	};

	for (auto it: ranges::iota_view(0, k + 1))
		if (check(hc + it * (__int128) a, dc + (k - it) * (__int128) w))
		{
			cout << "YES\n";

			return;
		}

	cout << "NO\n";
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}