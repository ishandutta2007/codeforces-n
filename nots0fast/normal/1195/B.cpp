#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
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
#define double long double
#define MAX 600100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

void deal(){
	ll n , k;
	cin>>n>>k;
	ll lo = 0, hi = 1e9;
	while(lo < hi){
		ll mid = (lo + hi) / 2;
		if(mid* (mid + 3 ) < 2*(n+k))
			lo = mid+1;
		else
			hi = mid;
	}
	ll i = lo;
	ll j = n - i;
	cout<<j;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}