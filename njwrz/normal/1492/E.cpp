/*
???????????????????
DP???????????????
??????????????????
?????????????????
??????????????????
????????????????????
?????????????????????
ll?? int????????????
 dp ????????????????
?????????????????
?????????????????????
?????????????????
????????????????
?????????????????
???????????????????
???????????????????
?????????????????????
??????????????????
?????????????????
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
int n,m;
V<V<int> > v;
int check(int x,int y){
	int cnt=0;
	rep(i,0,m){
		cnt+=v[x][i]!=v[y][i];
	}
	RE cnt;
} 
int cnt,p[5];
void solve(){
	rep(i,0,n){
		int t=check(i,n);
		if(t>3)RE;
		if(t==3){
			bool ff=1;
			rep(j,0,m){
				if(v[n][j]==-1){
					ff=0;
					v[n][j]=v[i][j];break;
				}
			}
			if(ff)RE;
		}
	}
	rep(i,0,m)if(v[n][i]==-1)v[n][i]=1;
	cout<<"Yes\n";
	rep(i,0,m)cout<<v[n][i]<<' ';
	exit(0);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	v.resize(n+1);
	rep(i,0,n){
		v[i].resize(m);
		rep(j,0,m){
			cin>>v[i][j];
		}
	}
	int id=-1,maxi=0;
	rep(i,1,n){
		int t=check(0,i);
		if(t>maxi){
			maxi=t;
			id=i;
		}
	}
	if(maxi<=2){
		cout<<"Yes\n";
		rep(i,0,m)cout<<v[0][i]<<' ';RE 0;
	}else if(maxi>4){
		cout<<"No";RE 0;
	}
	rep(i,0,m){
		if(v[0][i]!=v[id][i]){
			p[++cnt]=i;
		}
	}
	FOR(i,1,cnt){
		FOR(j,1,cnt){
			if(i==j)continue;
			v[n]=v[0];
			v[n][p[i]]=v[id][p[i]];
			v[n][p[j]]=-1;
			solve();
		}
	}
	cout<<"No";
	RE 0;
}