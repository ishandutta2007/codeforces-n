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
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e5 + 10;
int dp[N];
vi g[N];

int res = 0;

void dfs(int node,int par = -1)
{
    int cc = 1;
    
    int flag = 0;
    
    for(auto x : g[node])
    {
        if(x == par) continue;
        
        dfs(x,node);
        
        cc = (cc*dp[x])%MOD;
        flag = 1;
    }
    
    if(flag == 0)
        dp[node] = cc;
    else
        dp[node] = (cc + cc)%MOD;
}

void dfs2(int node,int par = -1)
{
    res = (res + dp[node])%MOD;
    
 //   cout << node << ' ' << dp[node] << '\n';
    
    for(auto x : g[node])
    {
        if(x == par) continue;
        
        //update dp[x]
        if(g[x].size() == 1 && g[node].size() > 1)
            dp[x] = (dp[node] + dp[node])%MOD;
        else if(g[node].size() == 1 && g[x].size() == 1) dp[x] = dp[node];
        else if(g[node].size() > 1 && g[x].size() > 1) dp[x] = dp[node];
        
        dfs2(x,node);
    }
}

void solve()
{
   int n;
    cin >> n;
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   dfs(1);
   dfs2(1);

   cout << res; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}