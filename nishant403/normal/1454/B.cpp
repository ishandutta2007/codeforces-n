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
    
    int a[n];
    f(i,n) cin >> a[i];
    
    map<int,int> mp;
    
    f(i,n) mp[a[i]]++;
    
    int id = -1;
    
    f(i,n)
        if(mp[a[i]] == 1)
    {
        if(id == -1) id = i+1;
        else if(a[id-1] > a[i]) id = i+1;
    }
    
    cout << id << '\n'; 
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
   cin >> t;
    
    while(t--)
        
    solve();
}