#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")

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
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 6);
ll modulo = pow(10,9) + 7;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		ll id = -1, s = 0;
		fori(n){
			ll ed;
			cin>>ed;
			if(ed%2 == 1){
				id = i+1;
			}
			s+=ed;
		}
		ll kok = sqrt(s);
		bool seen = 0;
		for(ll i = 2; i<=kok; i++){
			if(s % i == 0){
				seen = 1;
				break;
			}
		}
		ll ans = n;
		if(!seen){
			--ans;
		}
		cout<<ans<<'\n';
		for(ll i = 1; i<=n; i++){
			if(i == id && !seen){
				
			}
			else{
				cout<<i<<' ';
			}
		}
		cout<<'\n';
	}
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}