/*

DP





ll int
 dp 










*/
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int p[5005],a[5005],dp[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		while(a[i]%2==0){
			p[i]++;
			a[i]/=2;
		}
	}
	int ans=0;
	FOR(i,1,n){
		dp[i]=1;
		rep(j,1,i){
			if(a[j]%a[i]==0&&(p[i]-p[j]==i-j||p[i]<i-j))gmax(dp[i],dp[j]+1); 
		}
		gmax(ans,dp[i]);
	}
	cout<<n-ans;
	RE 0;
}