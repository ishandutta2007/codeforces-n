
// Problem : G. Vasya and Maximum Profit
// Contest : Codeforces - Educational Codeforces Round 59 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1107/G
// Memory Limit : 256 MB
// Time Limit : 3500 ms
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
const int N = 3e5 + 10;
const ll INF = (ll)1e18 + 10;
 
int n, a;
int d[N], c[N];
stack< pair<int, ll> > resLog;
ll lazyAdd;
ll res;
 
int main() {
 
	scanf("%d%d", &n, &a);
	for (int i = 1; i <= n; i++) scanf("%d%d", &d[i], &c[i]);
	for (int at = 1; at <= n; at++) {
		ll gain = a - c[at];
		lazyAdd += gain;
		int streakCnt = 0;
		ll currDiff = d[at] - d[at - 1];
		ll currres = -INF;
		while (!resLog.empty()) {
			auto top = resLog.top();
			ll prevDiff = top.first;
			ll prevres = top.second;
			if (prevDiff > currDiff) break;
			currres = max(currres, prevres + prevDiff * prevDiff - currDiff * currDiff);
			resLog.pop();
			streakCnt++;
		}
		if (streakCnt > 0) {
			if (!resLog.empty()) {	
				auto top = resLog.top();
				ll prevres = top.second;
				if (prevres < currres) resLog.push({currDiff, currres});
				else currres = prevres;
			}
			else resLog.push({currDiff, currres});
		}
		ll singleres = gain - lazyAdd;
		if (!resLog.empty()) {
			auto top = resLog.top();
			ll prevres = top.second;
			if (singleres > prevres) {
				resLog.push({0, singleres});
				currres = singleres;
			}
			else currres = prevres;
		}
		else {
			resLog.push({0, singleres});
			currres = singleres;
		}
 
		res = max(res, currres + lazyAdd);
	}
 
	cout<<res;
}