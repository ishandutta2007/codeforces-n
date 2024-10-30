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
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6)+10)

deque<ll> arr;
deque<pair<ll,ll> > que;
ll ans[MAX][2];


void deal(){
	ll n , q;
	cin>>n>>q;
	arr.resize(n);
	ll mx = 0;
	fori(n){
		cin>>arr[i];
		if(arr[i] >arr[mx])
			mx = i;
	}
	fori(q){
		ll yr;
		cin>>yr; --yr;
		que.pb(mp(yr,i));
	}
	sort(que.begin(), que.end());
	fori(mx){
		ll a = arr[0], b = arr[1];
	//	cout<<"we ballin at "<<i<<endl;
		while(que.size() && que[0].ff == i){
			fori(2)
				ans[que[0].ss][i] = arr[i];
			que.pop_front();
		}
		arr.pop_front();
		arr.pop_front();
		arr.push_front(max(a,b));
		arr.push_back(min(a,b));
	}
	while(que.size()){
		ans[que[0].ss][0] = arr[0];
		ans[que[0].ss][1] = arr[(que[0].ff-mx)%(n-1) + 1]; 
		que.pop_front();
	}
	fori(q){
		forj(2)
			cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
		
}





int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}