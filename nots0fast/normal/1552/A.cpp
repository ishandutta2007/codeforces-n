#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define mt make_tuple
#define MAX (int)(4*pow(10,5) + 5)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		string a;
		cin>>a;
		string b = a;
		sort(b.begin(), b.end());
		ll s = 0;
		fori(n){
			if(a[i] != b[i]){
				++s;
			}
		}
		cout<<s<<'\n';
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}