#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define F first
#define S second 
#define pb push_back
#define endl "\n"

#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { // from [0, x-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int getInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
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


i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    string s;
    cin>>s;
    int n = s.length();

    vector<int> cou;
    string x;

    int coun = 1;
    char c = s[0];
    for(int i=1;i<n;i++)
    {
        if(s[i]!=c)
        {
            cou.pb(coun);
            x.pb(c);
            coun = 1;
            c = s[i];    
        }
        else
        {
            coun++;
        }
    }
    cou.pb(coun);
    x.pb(c);

    n = x.length();
    if(n%2==0)
    {
        cout<<0<<endl;
        return 0;
    }
    
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        if(i==j)
            break;

        if(x[i]!=x[j] || cou[i]+cou[j]<3ll)
        {
            cout<<0<<endl;
            return 0;
        }
    }

    int z = (n)/2;
    if(cou[z]<2ll)
    {
        cout<<0<<endl;
        return 0;
    }

    cout<<cou[z]+1<<endl;
    
}