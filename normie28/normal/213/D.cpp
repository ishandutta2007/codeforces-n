/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

//---------END-------//
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
vector<pii(ld)> bruh;
ld x,y,pi=3.14159265358979;
int main()
{
	fio;
	bruh.emplace_back(0,0);
	x+=cos(pi/5)*10;
	y+=sin(pi/5)*10;
	bruh.emplace_back(x,y);
	x+=cos(2*pi-pi/5)*10;
	y+=sin(2*pi-pi/5)*10;
	bruh.emplace_back(x,y);
	x+=cos(2*pi-3*pi/5)*10;
	y+=sin(2*pi-3*pi/5)*10;
	bruh.emplace_back(x,y);
	x+=cos(2*pi-pi)*10;
	y+=sin(2*pi-pi)*10;
	bruh.emplace_back(x,y);
	x+=cos(2*pi-7*pi/5)*10;
	y+=sin(2*pi-7*pi/5)*10;
	bruh.emplace_back(x,y);
	cin>>n;
	cout<<5+4*(n-1)<<endl;
	x=0;y=0;
		cout<<fixed<<setprecision(9)<<bruh[0].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<bruh[0].se;
		cout<<endl;
		
		cout<<fixed<<setprecision(9)<<bruh[3].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<bruh[3].se;
		cout<<endl;
		
		cout<<fixed<<setprecision(9)<<bruh[1].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<bruh[1].se;
		cout<<endl;
		
		cout<<fixed<<setprecision(9)<<bruh[4].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<bruh[4].se;
		cout<<endl;
		
		cout<<fixed<<setprecision(9)<<bruh[2].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<bruh[2].se;
		cout<<endl;
		x=0;
		y=0;
		for (i=1;i<n;i++)
		{
			x+=bruh[2].fi;
			y+=bruh[2].se;
		cout<<fixed<<setprecision(9)<<x+bruh[3].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<y+bruh[3].se;
		cout<<endl;
		
		cout<<fixed<<setprecision(9)<<x+bruh[1].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<y+bruh[1].se;
		cout<<endl;
		
		cout<<fixed<<setprecision(9)<<x+bruh[4].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<y+bruh[4].se;
		cout<<endl;
		
		cout<<fixed<<setprecision(9)<<x+bruh[2].fi;
		cout<<' ';
		cout<<fixed<<setprecision(9)<<y+bruh[2].se;
		cout<<endl;
		}
		for (i=1;i<=n;i++)
		{
			cout<<1+(i-1)*4<<' '<<3+(i-1)*4<<' '<<5+(i-1)*4<<' '<<2+(i-1)*4<<' '<<4+(i-1)*4<<endl;
		}
		for (i=1;i<=5+4*(n-1);i++) cout<<i<<' ';
		for (i=n-2;i>=-1;i--) cout<<5+4*i<<' ';
		
}