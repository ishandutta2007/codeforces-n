#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
V<int> v[200005],node[200005];
int ans[200005],a[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)v[i].clear(),node[i].clear();
	FOR(i,1,n){
		int x;
		cin>>x;a[i]=x;
		v[x].PB(i);
	}
	FOR(i,1,n){
		FOR(j,1,(int)v[i].size()){
			node[j].PB(v[i][j-1]);
		}
	}
	FOR(i,1,n)if(!node[i].empty()){
		rep(j,0,(int)node[i].size()){
			ans[node[i][j]]=a[node[i][(j+1)%((int)(node[i].size()))]];
		}
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}