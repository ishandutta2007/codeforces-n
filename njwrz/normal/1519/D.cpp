//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='

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
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int a[5005],b[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int ans=0,maxi=0;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i],ans+=a[i]*b[i];
	maxi=ans;
	FOR(mid,1,n){
		int now=maxi;
		rep(j,0,min(mid,n-mid+1)){
			now-=a[mid-j]*b[mid-j]+a[mid+j]*b[mid+j]-a[mid-j]*b[mid+j]-a[mid+j]*b[mid-j];
			gmax(ans,now);
		}
	}
	rep(mid,1,n){
		int now=maxi;
		FOR(j,0,min(mid-1,n-mid-1)){
			now-=a[mid-j]*b[mid-j]+a[mid+j+1]*b[mid+j+1]-a[mid-j]*b[mid+j+1]-a[mid+j+1]*b[mid-j];
			gmax(ans,now);
		}
	}
	cout<<ans;
	RE 0;
}