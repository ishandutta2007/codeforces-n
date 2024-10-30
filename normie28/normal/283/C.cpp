
// Problem : C. Coin Troubles
// Contest : Codeforces - Codeforces Round #174 (Div. 1)
// URL : https://codeforces.com/problemset/problem/283/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int maxn=1e5+20,inf=2e9+20,mod=1e9+7;
ll n,q,t,a[maxn];
ll f[maxn],bf[maxn],mark[maxn],c[maxn];
void dfs(int u){
	mark[u]++;
	if(mark[f[u]]==1){
		cout<<0;
		exit(0);
	}
	if(f[u] && !mark[f[u]]) dfs(f[u]);
	c[u]=c[f[u]]+1;
	t-=c[u]*a[u];
	mark[u]++;
}
void bdfs(int u){
	mark[u]++;
	if(bf[u] && !mark[bf[u]]) bdfs(bf[u]);
	a[u]+=a[bf[u]];
	if(a[u]>t) a[u]=t+20;
}
ll dp[maxn];
int main(){
	fio;
	cin>>n>>q>>t;
	for(int i=1;i<=n;++i) cin>>a[i];
	while(q--){
		int x,y;
		cin>>x>>y;
		f[x]=y;
		bf[y]=x;
	}
	c[0]=-1;
	for(int i=1;i<=n;++i){
		if(!mark[i]) dfs(i);
	}
	fill(mark,mark+n+1,0);
	for(int i=1;i<=n;++i){
		if(!mark[i]) bdfs(i);
	}
	if(t<0) return cout<<0, 0;
	dp[0]=1;
	for(int j=1;j<=n;++j){
		for(int i=1;i<=t;++i){
			ll z=i-a[j];
			if(z<0) continue;
			dp[i]=(dp[i]+dp[z])%mod;
		}
	}
	cout<<dp[t];
}