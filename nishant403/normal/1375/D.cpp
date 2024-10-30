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


void solve()
{
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
    
    vi res;
    
   int ff = 1; 
    
   while(!is_sorted(a,a+n))
   {
       vector<int> fre(n+1,0);
       f(i,n) fre[a[i]]++;
       
       int me = -1;
       
       f(i,n+1) if(fre[i] == 0)
       {
           me = i;
           break;
       }
       
       if(me < n)
       {
           a[me] = me;
           res.pb(me);
       }
       else if(me == n)
       {
           //find first inappropriate position and append there
           int id = -1;
           
           f(i,n) if(a[i] != i)
           {
               id = i;
               break;
           }
           
           a[id] = me;
           res.pb(id);
       }
   }
   
   cout << res.size() << '\n';
    for(auto x : res) cout << x + 1 << ' ';
    cout << '\n';
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}