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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(3*pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

ll arr[MAX];

void deal(){
	ll n,m;
	cin>>n>>m;
	fori(n)
		cin>>arr[i];
	ll a = 0, b = m+1;
	while(a<b){
		ll c= (a+b)>>1;
		ll pv = 0;
		fori(n){
			if(arr[i] + c >= m){
				ll one = arr[i] + c;
				one%=m;
				if(one < pv)
					pv = max(pv, arr[i]);
			}
			else{
				if(arr[i] + c >= pv)
					pv = max(pv, arr[i]);
				else
					pv = MAX;
			}
		}
		if(pv == MAX)
			a=c+1;
		else
			b=c;
	}
	
	cout<<a<<endl;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1