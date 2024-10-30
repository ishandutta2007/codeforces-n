//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)))
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update>
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
}

ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
}

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    x = x%mod;
    ex = ex % (mod-1);
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
ld dp[105][105][105];
int r,s,p;

void solve()
{
    cin>>r>>s>>p;
    memset(dp,0,sizeof(dp));
    dp[r][s][p] = 1.0;
    ld ne;
    int coun = r+s+p;
    for(int i=r;i>=0;i--)
    {
        for(int j=s;j>=0;j--)
        {
            for(int k=p;k>=0;k--)
            {
                coun = (i>0)+(j>0) +(k>0);
                if(coun<=1)
                    continue;
                if(j>0) {
                    ne = (i * j + 0.0) / (i * j + j * k + i * k + 0.0);
//                    cout<<ne<<endl;
                    dp[i][j - 1][k] += ne * dp[i][j][k];
                }

                if(k>0) {
                    ne = (j * k + 0.0) / (i * j + j * k + i * k + 0.0);
                    dp[i][j][k - 1] += ne * dp[i][j][k];
                }

                if(i>0) {
                    ne = (k * i + 0.0) / (i * j + j * k + i * k + 0.0);
                    dp[i - 1][j][k] += ne * dp[i][j][k];
                }

            }
        }
    }

    cout<<setprecision(15);
    ld ans = 0;
    for(int i=1;i<=r;i++)
    {
        ans+= dp[i][0][0];
    }
    cout<<ans<<" ";

    ans = 0;
    for(int i=1;i<=s;i++)
    {
        ans+= dp[0][i][0];
    }
    cout<<ans<<" ";

    ans = 0;
    for(int i=1;i<=p;i++)
    {
        ans+= dp[0][0][i];
    }
    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}