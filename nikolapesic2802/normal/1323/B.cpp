
// Problem : A. Even Subset Sum Problem
// Contest : Codeforces Round #626 (Div. 2, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1323/problem/A
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=40001;
vector<int> a(N),b(N);
int n,m;
ll k,sol;
void p(ll a1,ll b1){
	if(a1>n||b1>m)
		return;
	int aa=0,bb=0;
	for(int i=a1-1;i<n;i++)
		if(a[i]-(i==a1-1?0:a[i-a1])==a1)
			aa++;
	for(int i=b1-1;i<m;i++)
		if(b[i]-(i==b1-1?0:b[i-b1])==b1)
			bb++;
	sol+=(ll)aa*bb;
}
int main()
{
	scanf("%i %i %lld",&n,&m,&k);
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%i",&b[i]);
	for(int i=1;i<n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<m;i++)
		b[i]+=b[i-1];
	for(ll i=1;i*i<=k;i++)
		if(k%i==0){
			p(i,k/i);
			if(k/i!=i)
				p(k/i,i);
		}
	printf("%lld\n",sol);
	return 0;
}