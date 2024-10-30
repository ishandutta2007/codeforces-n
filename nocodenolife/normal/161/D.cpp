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

const int maxn = 50005;
const int maxk = 505;

const ll inf = 1e9 + 7;

int n,k;

int coun[maxn][maxk];
vector<int> tre[maxn];
int ans = 0;

void dfs(int ver, int par)
{
    coun[ver][0] = 1;
    for(auto c:tre[ver])
    {
        if(c==par)
            continue;
        dfs(c,ver);
        for(int i=1;i<maxk;i++)
        {
            coun[ver][i]+=coun[c][i-1];
        }
    }
    ans+= coun[ver][k];
    int u=0,v;
    for(auto c:tre[ver])
    {
        if(c==par)
            continue;
        for(int i=0;i<k-1;i++)
        {
            v = k - (i+1);
            u+= coun[c][i] * (coun[ver][v] - coun[c][v-1]);
        }
    }
    ans = ans + u/2;

}

void solve()
{
    cin>>n>>k;
    int u,v;

    memset(coun,0, sizeof(coun));
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        tre[u].pb(v);
        tre[v].pb(u);
    }
    dfs(1,-1);
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