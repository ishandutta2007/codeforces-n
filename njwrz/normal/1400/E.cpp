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
int n,a[5005];
int dfs(int l,int r){
	if(l>r)RE 0;
	if(l==r){
		RE min(a[l],1);
	}
	int mini=2e9,it=0;
	FOR(i,l,r){
		if(a[i]<mini){
			mini=a[i];
			it=i;
		}
	}
	FOR(i,l,r)a[i]-=mini;
	RE min(r-l+1,dfs(l,it-1)+dfs(it+1,r)+mini);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	cout<<dfs(1,n);
	RE 0;
}