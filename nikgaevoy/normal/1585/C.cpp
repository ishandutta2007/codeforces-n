#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


ll solve_half(vector<int> arr, int k, bool ret)
{
	ranges::sort(arr);

	ll ans = 0;

	auto pop = [&]()
	{
		arr.resize(max((ssize_t) 0, ssize(arr) - k));
	};

	if (!ret && !arr.empty())
	{
		ans += arr.back();

		pop();
	}

	while (!arr.empty())
	{
		ans += 2 * arr.back();
		pop();
	}

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<int> arr(n);

	copy_n(istream_iterator<decltype(arr)::value_type>(cin), arr.size(), arr.begin());

	vector<int> pos, neg;

	for (auto it: arr)
		if (it > 0)
			pos.push_back(it);
		else if (it < 0)
			neg.push_back(abs(it));

	cout << min(solve_half(pos, k, false) + solve_half(neg, k, true),
	            solve_half(pos, k, true) + solve_half(neg, k, false)) << endl;
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