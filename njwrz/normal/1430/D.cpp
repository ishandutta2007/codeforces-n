/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
char c[200005];
int p[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>c[i];
	}
	int cnt=1,m=0;
	FOR(i,2,n){
		if(c[i]==c[i-1]){
			cnt++;
		}else{
			p[++m]=cnt;cnt=1;
		}
	}
	p[++m]=cnt;
	int l=1,ans=0;
	FOR(i,1,m){
		gmax(l,i);
		ans++;
		while(l<=m&&p[l]==1)l++;
		if(l<=m)p[l]--;
		else{
			--m;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}