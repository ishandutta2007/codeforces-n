#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) cerr<<#x<<" = " << (x) << endl
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;


const int MAX = 2e5;
ll N, Q;

ll strenghs[MAX];
ll arrows[MAX];

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> Q;
	for (int i(0); i < N; ++i)
		cin >> strenghs[i];
	for (int i(0); i < Q; ++i)
		cin >> arrows[i];
	
	for (int i(0); i < N-1; ++i)
		strenghs[i+1] += strenghs[i];

	ll arrows_thrown(0);

	for (int t(0); t < Q; ++t)
	{
		arrows_thrown += arrows[t];
		ll i = upper_bound(strenghs, strenghs + N, arrows_thrown) - strenghs;
		if (i == N)
			arrows_thrown = 0, i = 0;
		cout << N-i << '\n';
	}
}