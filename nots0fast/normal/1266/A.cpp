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
#define pb(a) push_back(a)
typedef double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)
#define sqrtn (int)(670)

bool check ( string& a){
	ll s = 0;
	bool seen = 0;
	fori(a.length()){
		if((a[i]-'0')%2 == 0){
			seen = 1;
		}
		s += (a[i] -'0');
	}
	return (s%3 == 0 && seen);
}

void deal(){
	ll n;
	cin>>n;
	fori(n){
		string a;
		cin>>a;
		bool ans = 0;
		forj(a.length()){
			if(a[j] == '0'){
				string b = a;
				b.erase(j,1 );
		//		cout<<b<<endl;
				ans = check(b);
				break;
			}
		}
		if(ans){
			cout<<"red\n";
		}
		else{
			cout<<"cyan\n";
		}
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}