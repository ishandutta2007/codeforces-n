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
 int a,b,c,d;
    cin >> a >> b >> c >> d;
    
 int x,y,x1,y1,x2,y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
     
   int flag = 1;
    
  if(a > 0 || b > 0 ) 
  {
   if(x == x1 && x == x2) flag = 0;
   
   if(a>b) 
   {
       if(x-x1 < a-b) flag = 0;
   }
   else if(b > a) 
   {
       if(x2-x < b-a) flag = 0;
   }
  }
   
    
   if(c > 0 || d > 0 ) 
  {
   if(y == y1 && y == y2) flag = 0;
   
   if(c>d) 
   {
       if(y-y1 < c-d) flag = 0;
   }
   else if(d>c) 
   {
       if(y2-y < d-c) flag = 0;
   }
  } 
    
    
    if(flag == 1) cout <<"YES\n";
    else cout <<"NO\n";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}