#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << "\n"

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;


const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, d; std::cin >> n >> d;
	vi	a(n); for (auto &v : a) std::cin >> v;
	int	m; std::cin >> m;
	std::sort(all(a));

	ll	ans(0);
	for (int i(0); i < std::min(n, m); ++i)
		ans += a[i];
	ans -=std::max(0, (m-n))*d;
	pnl(ans);
}