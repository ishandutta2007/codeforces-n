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
#define MAX 300300
#define MAX2 220
#define pb(a) push_back(a)
double eps = 1e-12;
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;
int arr[MAX];
vector<pair<int,int> > all;
set<int> unvisited;
void deal(){
	int n;
	cin>>n;
	int mn = pow(10,9);
	fori(n){
		cin>>arr[i];
		all.pb(mp(arr[i], i));
		unvisited.insert(i);
	}
	sort(all.begin(), all.end());
	fori(all.size()){
		auto it = unvisited.end();
		--it;
		int fr = *it;
		if(all[i].ss != fr)
			mn = min(mn, all[i].ff / (int)fabs(all[i].ss - fr));
		fr = *unvisited.begin();
		if(all[i].ss != fr)
			mn = min(mn, all[i].ff / (int)fabs(all[i].ss - fr));
		unvisited.erase(all[i].ss);
	}
	cout<< mn;
}



int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}