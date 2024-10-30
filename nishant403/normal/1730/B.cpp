#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define int long long
#define pb push_back
#define S second
#define F first
#define f(i, n) for (int i = 0; i < n; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define precise(x) fixed << setprecision(x)

const int MOD = 1e9 + 7;

int mod_pow(int a, int b, int M = MOD)
{
    if (a == 0)
        return 0;
    b %= (M - 1); // M must be prime here

    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }

    return res;
}

const int inf = 1e9 + 1000;

void solve()
{
    int n;
    cin >> n;

    pii a[n];
    f(i, n) cin >> a[i].F;
    f(i, n) cin >> a[i].S;

    double l = 0;
    double r = inf;
    double res = -1;
    double pos = -1;

    f(i, 200)
    {
        double mid = (l + r) / 2.000;

        pair<double, double> range = {-inf, inf};

        f(i, n)
        {
            pair<double, double> range2 = {a[i].F - (mid - a[i].S), a[i].F + (mid - a[i].S)};
            pair<double, double> inter;
            inter.F = max(range.F, range2.F);
            inter.S = min(range.S, range2.S);

            range = inter;
        }

        if (range.F <= range.S)
        {
            res = mid;
            pos = range.F;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << precise(10) << pos << '\n';
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}