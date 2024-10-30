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

const int N = 503;

int dp[N][N];
int go[N];
int n;

void dfs(int i,int j,int val,int id)
{
    if(i <= 0 || j <= 0 || i > n || j > n) return;
    
    if(dp[i][j] != 0) return;
    
    if(go[id] == 0) return;
    
    go[id]--;
    
    dp[i][j] = val;
    
    dfs(i,j-1,val,id);
    dfs(i+1,j,val,id);
    dfs(i,j+1,val,id);
}

void solve()
{
   cin >> n;
   for(int i=1;i<=n;i++) cin >> go[i];  
   for(int i=1;i<=n;i++) dfs(i,i,go[i],i); 
 
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=i;j++) cout << dp[i][j] << ' ';
      cout <<'\n';
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}