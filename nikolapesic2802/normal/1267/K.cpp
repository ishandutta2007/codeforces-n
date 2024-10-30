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
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}

const int L=21;
vector<ll> fact(1,1);
ll getWays(vector<int> a){
    a.pb(INT_MAX);
    int r=-1;
    ll sol=1;
    for(int i=2;i<a.size()+1;i++){
        while(a[r+1]<i)
            r++;
        sol*=r-i+3;
    }
    int cnt=1;
    for(int i=1;i<a.size();i++)
        if(a[i]==a[i-1])
            cnt++;
        else
            sol/=fact[cnt],cnt=1;
    sol/=fact[cnt];
    return sol;
}
int main()
{
    for(int i=1;i<L;i++)
        fact.pb(fact.back()*i);
    int t;
    scanf("%i",&t);
    while(t--){
        ll k;
        cin >> k;
        vector<int> a;
        for(int i=2;i<L&&k;i++)
            a.pb(k%i),k/=i;
        sort(all(a));
        ll sol=getWays(a);
        if(a[0]==0)
            reverse(all(a)),a.pop_back(),reverse(all(a)),sol-=getWays(a);
        printf("%lld\n",sol-1);
    }
    return 0;
}