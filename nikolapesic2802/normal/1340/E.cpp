
// Problem : E. Nastya and Bees
// Contest : Codeforces - Codeforces Round #637 (Div. 1) - Thanks, Ivan Belonogov!
// URL : http://codeforces.com/contest/1340/problem/E
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int N=5001;
vector<vector<int> > graf(N);
int d[N][N],n,m;
vector<int> b(3);
void print(){
	printf("%i %i %i\n",b[0]+1,b[1]+1,b[2]+1);
	fflush(stdout);
}
int cnt=0;
bool doit(){
	if(cnt==n){
		while(1);
		return 1;
	}
	cnt++;
	print();
	int pos;
	scanf("%i",&pos);
	pos--;
	for(int i=0;i<3;i++){
		if(d[pos][b[i]]==0)
			return 1;
		if(d[pos][b[i]]==1){
			b[i]=pos;
			print();
			return 1;
		}
	}
	vector<int> pored;
	for(auto p:graf[pos])
		pored.pb(p);
	while(pored.size()<3)
		pored.pb(pored.back());
	vector<int> perm={0,1,2};
	int bst=INT_MAX;
	vector<int> gde;
	do{
		int sum=0;
		for(int i=0;i<3;i++){
			sum+=d[pored[i]][b[perm[i]]];
		}
		if(sum<bst)
			bst=sum,gde=perm;
	}while(next_permutation(all(perm)));
	assert(bst!=INT_MAX);
	for(int i=0;i<3;i++){
		int tr=gde[i];
		int gde=-1;
		for(auto p:graf[b[tr]]){
			if(d[pored[i]][b[tr]]>d[pored[i]][p])
				gde=p;
		}
		assert(gde!=-1);
		b[tr]=gde;
	}
	return 0;
}
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			d[i][j]=INT_MAX;
		queue<int> q;
		q.push(i);
		d[i][i]=0;
		while(q.size()){
			int tr=q.front();
			q.pop();
			for(auto p:graf[tr]){
				if(d[i][p]>d[i][tr]+1){
					d[i][p]=d[i][tr]+1;
					q.push(p);
				}
			}
		}
	}
	while(!doit());
	return 0;
}