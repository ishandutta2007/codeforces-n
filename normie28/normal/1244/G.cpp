
// Problem : G. Running in Pairs
// Contest : Codeforces - Codeforces Round #592 (Div. 2)
// URL : https://codeforces.com/contest/1244/problem/G
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
const int N = 1e6 + 100;
 
ll n, k, sum, res[N];
bool mark[N];
 
int main() {
	fio;
	cin >> n >> k;
	if ((sum = (1 + n) * n / 2) > k) {
		cout << -1;
		return 0;
	}
	k -= sum;
 
	int p = 1;
	for (int i = n; i; i--) {
		while (i > p && (i - p) > k)
			p++;
		if (i <= p)
			break;
		mark[i] = true;
		res[p] = i;
		sum += i - p;
		k -= i - p;
		p++;
	}
 
	p = 1;
	for (int i = 1; i <= n; i++)
		if (res[i] == 0) {
			while (mark[p])
				p++;
			res[i] = p++;
		}
	
	cout << sum << endl;
	for (int i = 1; i <= n; i++)
		cout << i << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}