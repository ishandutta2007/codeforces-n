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
#define MAX (int)(pow(10,6) + 5)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;

bool gg(vector<vector<char> >& arr, ll w, ll h, ll i , ll j){
	for(ll dx = -1; dx<=1; dx++){
		for(ll dy = -1; dy<=1; dy++){
			ll x = i + dx, y = j + dy;
			if(x > -1 && y > -1 && x < w && y < h && arr[x][y]=='1'){
				return 0;
			}
		}
	}
	return 1;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll w, h;
		cin>>w>>h;
		vector<vector<char> > arr(w, vector<char>(h, '0'));
		ll i = 0, j = 0;
		while(j < h){
			if(gg(arr, w, h, i, j)){
				arr[i][j] = '1';
			}
			j+=2;
		}
		i = 0, j = h-1;
		while(i < w){
			if(gg(arr, w, h, i, j)){
				arr[i][j] = '1';
			}
			i+=2;
		}
		i = w - 1, j = h-1;
		while(j>-1){
			if(gg(arr, w, h, i, j)){
				arr[i][j] = '1';
			}
			j-=2;
		}
		i = w-1, j = 0;
		while(i>-1){
			if(gg(arr, w, h, i, j)){
				arr[i][j] = '1';
			}
			i-=2;
		}
		fori(w){
			forj(h){
				cout<<arr[i][j];
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}