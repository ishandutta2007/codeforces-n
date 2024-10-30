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

void solve(void)
{
	int n;
	read(n);
	vi a(n);
	readv(a);
	FOR(i,0,n)
		a[i]--;

	vi ans(n, -1);
	
	FOR(i,0,n)
	{
		if (ans[i] != -1) continue;

		int cnt(1);
		vi to_add;
		int cur(i);
		cur = a[i];
		to_add.pb(i);
		while (cur != i)
		{
			cnt++;
			to_add.pb(cur);
			cur = a[cur];
		}

		for (auto v : to_add)
			ans[v] = cnt;
	}

	FORR(v, ans)
	cout << v << ' ';
	cout << '\n';
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q;
	read(q);
	while (q--)
		solve();
}