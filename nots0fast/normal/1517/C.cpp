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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(100001)
#define ch (int)(500)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;


void deal(){
	ll t = 1;
//	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		
		vector<ll> arr(n);
		
		fori(n){
			cin>>arr[i];
		}
		
		vector<vector<ll> > diog(n, vector<ll>(n, 0));
		
		fori(n){
			ll left = arr[i] - 1;
			ll x = i, y = i;
			diog[x][y]  = arr[i];
			
			
			while(left){
				if(y-1 >= 0 && diog[x][y-1] == 0){
					--y;
				}
				else{
					++x;
				}
				--left;
				diog[x][y] = arr[i];
			}
			
		}
		
		fori(n){
			forj(i+1){
				cout<<diog[i][j]<<' ';
			}
			cout<<'\n';
		}
		
	}
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();  
}