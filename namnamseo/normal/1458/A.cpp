#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;

int n, m;
ll a[maxn];
ll b[maxn];

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main()
{
	cppio();
	cin >> n >> m;
	rrep(i, n) cin >> a[i];
	rrep(i, m) cin >> b[i];

	ll r = 0;
	rrep(i, n-1) {
		r = gcd(r, abs(a[i+1]-a[1]));
	}

	rrep(i, m) {
		ll x = gcd(r, a[1]+b[i]);
		cout << x << '\n';
	}

	return 0;
}