#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[1005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(n>m){
		cout<<0;RE 0;
	}
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	rep(i,1,n){
		FOR(j,i+1,n){
			ans=ans*(a[j]-a[i])%m;
		}
	}
	cout<<ans;
	RE 0;
}