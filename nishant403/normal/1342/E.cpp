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

const int MOD = 998244353;

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

const int N = 2e5 + 10;

int fact[N];
int ifact[N];

void init()
{
    fact[0] = 1;
    
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*i)%MOD;
    
    ifact[N-1] = mod_pow(fact[N-1],MOD-2);
    
    for(int i=N-2;i>=0;i--) 
        ifact[i] = (ifact[i+1]*(i+1))%MOD;
}

int ncr(int n,int r)
{
 if(r>n) return 0;
    
 int res = fact[n];
    
 res = (res*ifact[r])%MOD;
 res = (res*ifact[n-r])%MOD;
    
  return res;
}

//assign n distinct objects into k distinct boxes so that each box has atleast one element : 
//Stirling number of 2nd kind * n!

int go(int n,int k)
{
   int res = 0;
    
   for(int i=0;i<k;i++)
   {
       if(i & 1) res -= mod_pow(k - i,n)*ncr(k,i);
       else res += mod_pow(k-i,n)*ncr(k,i);
       
       res %= MOD;
       if(res < 0) res += MOD;
   }
    
   return res;
}

void solve()
{
   int n,k;
    cin >> n >> k;
    
   if(k > n-1) 
   {
       cout << 0;
       return;
   }
 
   if(k == 0)
   {
       cout << fact[n];
       return;
   }
    
   //we need to have exactly col distinct values.
   int col = n - k;
   int res = ncr(n,col);
   res = (res*go(n,col))%MOD;
   res %= MOD;
   res = (res + res)%MOD; 
    
   cout << res;
}

signed main()
{
    init();
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}