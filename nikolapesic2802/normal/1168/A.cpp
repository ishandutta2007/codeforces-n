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

const int N=3e5+5;
vector<int> a(N);
int n,m;
bool test(int t)
{
    //printf("Testiram %i!\n",t);
    int last=0;
    for(int i=0;i<n;i++)
    {
        int nxt=(a[i]+t)%m;
        //printf("%i: %i %i   %i-%i\n",t,i,last,a[i],nxt);
        if(nxt<a[i])
        {
            if(nxt>=last)
                continue;
            last=max(last,a[i]);
        }
        else
        {
            if(nxt<last)
                return false;
            last=max(last,a[i]);
        }
    }
    return true;
}
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    //test(1);
    //return 0;
    int l=0,r=m-1;
    while(l<r)
    {
        int t=(l+r)>>1;
        if(test(t))
            r=t;
        else
            l=t+1;
    }
    printf("%i\n",l);
    return 0;
}