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
	
	std::string s; std::cin >> s;
	bool	word = false;
	for (int i(0); i < s.size(); ++i)
	{
		if (i < s.size() - 2 and s[i] == 'W' and s[i+1] == 'U' and s[i+2] == 'B')
		{
			if (word) std::cout << " ";
			i+=2;
			word = false;
		}
		else
		{
			word = true;
			std::cout << s[i];
		}
	}
	std::cout << std::endl;

}