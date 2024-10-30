#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;
vi g[N];
vector<pii> qq[N];
int a[N];
int n,q;
int res[N];
int f[N];

void add(int id,int val)
{
    for(;id<N;id+=(id&-id)) f[id]+=val;
}

int sum(int x)
{
    int res = 0;
    for(;x;x-=(x&-x)) res+=f[x];
    return res;
}

void dfs(int node,int par = -1,int dep = 0)
{
    int vv = 1;
    if(dep == 1) vv = -1;
    
    for(auto x : qq[node])
    {
        if(x.S == 0) res[x.F] = a[node] + sum(x.F)*vv; 
        else add(x.F,x.S*vv);
    }
    
    for(auto x : g[node]) 
        if( x != par) dfs(x,node,dep^1);
    
    for(auto x : qq[node])
    if(x.S > 0) add(x.F,-x.S*vv);
}

signed main()
{
    fast;
    
    cin >> n >> q;
    
    f(i,n) cin >> a[i+1];
    
    int u,v,x;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    f(i,q)
    {
        cin >> x >> u;
        
        if(x == 1) cin >> v;
        else v = 0;
        
        qq[u].pb({i+1,v});    
        
        res[i+1] = 1e9;
    }
    
    dfs(1);
    
    f(i,q) if(res[i+1] != 1e9) cout << res[i+1] << '\n';
}