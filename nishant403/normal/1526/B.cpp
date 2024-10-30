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

const int N = 2e3 + 100;
int can[N];

int solve(int x)
{
    if(x == 0) return 1;
    if(x < 0) return 0;
    
    int & res = can[x];
    if(res != -1) return res;
    
    res = 0;
    
    int num = 11;
    
    while(num < N)
    {
       res |= solve(x - num);
        num*=10;
        num++;
    }
    
    return res;
}

void solve()
{
   f(i,N) can[i]  = -1;
    
   can[0] = 1; 
    
   int num = 11;
   
   while(num < N) 
   {
       can[num] = 1;
       num*=10;
       num++;
   }
   
    f(i,N) if(solve(i) == 0) ;
}


signed main()
{
    fast;
    
    solve();
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
    {
        int x;
        cin >> x;
        
        if(x >= N) cout << "YES\n";
        else if(can[x] == 1) cout << "YES\n";
        else cout <<"NO\n";
    }
}