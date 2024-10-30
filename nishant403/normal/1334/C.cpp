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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
   int n;
    cin >> n;
    
   pii a[n];
    f(i,n) cin >> a[i].F >> a[i].S;
 
  int res = a[0].F;
    
  f(i,n-1) res+=max((int)0,a[i+1].F-a[i].S);
    
  int temp = res;
    
  for(int i=1;i<n;i++)
  {
      //instead if i kill ith one first
      temp-=a[i-1].F;
      if(i==1) temp+=max((int)0,a[0].F-a[n-1].S);
      else temp+=max((int)0,a[i-1].F-a[i-2].S);
      
      temp+=a[i].F;
      temp-=max((int)0,a[i].F-a[i-1].S);
     
      res = min(res,temp);  
  }
    
  cout << res << '\n';  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}