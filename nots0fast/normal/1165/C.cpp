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
#define MAX 200100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;
int arr[MAX];

void deal(){
	int n;
	cin>>n;
	string a;
	cin>>a;
	string ans = "";
	for(int i=0; i<n; ){
		int nxt = i+1;
		while(nxt<n && a[i] == a[nxt])
			++nxt;
		ans+=a[i];
		if(nxt!=n)
			ans+=a[nxt];
		i = nxt+1;
	}
	if(((int)ans.length())&1)
		ans.erase(ans.end()-1);
	cout<<(a.length()- ans.length())<<'\n'<<ans;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





/* 
1
7 
...O...
..O.O..
.O.O.O.
O.O.O.O
.....O.
.......
.......




*/