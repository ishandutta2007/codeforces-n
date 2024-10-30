/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
int n,m,tot,a[1000005];
ll dp[1005][1005];
vector<int>p[1005];
ll getans(int l,int r){
	if(l>r) return 1;
	if(dp[l][r]!=-1) return dp[l][r];
	int mn=a[l],L,R,sz;
	for(int i=l+1;i<=r;i++)mn=min(a[i],mn);
	ll nl=0,nr=0;
	sz=p[mn].size(),L=p[mn][0],R=p[mn][sz-1];
	for(int i=l;i<=L;i++)
		(nl+=getans(l,i-1)*getans(i,L-1)%MOD)%=MOD;
	for(int i=R;i<=r;i++)
		(nr+=getans(R+1,i)*getans(i+1,r)%MOD)%=MOD;
	dp[l][r]=nl*nr%MOD;
	for(int i=0;i<sz-1;i++)
		(dp[l][r]*=getans(p[mn][i]+1,p[mn][i+1]-1))%=MOD;
	return dp[l][r];
}
int main(){
    fio;
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>a[i];
	tot=unique(a+1,a+m+1)-a-1;
	for (int i=1;i<=tot;i++)
		p[a[i]].push_back(i);
	if (tot>2*n) 
	return cout<<0,0;
	cout<<getans(1,tot);
}