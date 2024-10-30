
// Problem : E. Chips Puzzle
// Contest : Codeforces - Mail.Ru Cup 2018 Round 1
// URL : https://codeforces.com/problemset/problem/1054/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long LL;
//---------END-------// 
struct edge {
	LL flow;
	int dest, rev;
};
vector<edge> adj[2015];
int level[2015];
int last[2015];
LL summ = 0;
int n,m;
void push(int a, int b, LL c) {
	edge aa, bb;
	aa.dest = b;
	aa.rev = adj[b].size();
	aa.flow = c;
	bb.dest = a;
	bb.rev = adj[a].size();
	bb.flow = 0;
	adj[a].push_back(aa);
	adj[b].push_back(bb);
}
bool bfs(int s, int t) {
	queue<int> que;
	que.push(s);
	for(int i = 0;i<=n+m+1;i++) {
		level[i] = -1;
	}
	level[s] = 0;
	while(!que.empty()) {
		int a = que.front();
		que.pop();
		for(int i = 0;i<adj[a].size();i++) {
			edge b = adj[a][i];
			if(level[b.dest]==-1 && b.flow) {
				level[b.dest] = level[a]+1;
				que.push(b.dest);
			}
		}
	}
	return (level[t]>-1);
}
LL dfs(int a, int t, LL flow) {
	if(a==t) return flow;
	for(last[a];last[a]<adj[a].size();last[a]++) {
		edge &b = adj[a][last[a]];
		if(level[b.dest] == level[a]+1 && b.flow) {
			LL newFlow = dfs(b.dest, t, min(b.flow,flow));
			if(newFlow) {
				b.flow-=newFlow;
				adj[b.dest][b.rev].flow+=newFlow;
				return newFlow;
			}
		}
	}
	return 0;
}
LL dinic(int s, int t) {
	LL maxFlow = 0;
	while(bfs(s,t)) {
		for(int i = 0;i<=n+m+1;i++) {
			last[i] = 0;
		}
		while(LL flow = dfs(s,t,1e9)) {
			maxFlow+=flow;
		}
	}
	return maxFlow;
}
int main() {
	int a,b;
	LL c;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>c;
		push(i+m,1+n+m,c);
	}
	for(int i = 1;i<=m;i++) {
		cin>>a>>b>>c;
		push(0,i,c);
		push(i,a+m,1e9);
		push(i,b+m,1e9);
		summ+=c;
	}
	cout<<summ-dinic(0,n+m+1)<<endl;
	return 0;
}