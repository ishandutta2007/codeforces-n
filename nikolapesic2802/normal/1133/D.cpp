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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%i",&b[i]);
    map<pair<int,int>,int> cnt;
    int vec_nula=0;
    int maxx=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)
        {
            if(b[i]==0)
                vec_nula++;
        }
        else
        {
            int aa=gcd(abs(a[i]),abs(b[i]));
            cnt[{b[i]/aa,a[i]/aa}]++;
            cnt[{-1*b[i]/aa,-1*a[i]/aa}]++;
            maxx=max(maxx,cnt[{b[i]/aa,a[i]/aa}]);
            maxx=max(maxx,cnt[{-1*b[i]/aa,-1*a[i]/aa}]);
        }
    }
    printf("%i\n",maxx+vec_nula);
    return 0;
}