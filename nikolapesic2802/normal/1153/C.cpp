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

int main()
{
	int n;
	scanf("%i",&n);
	int c1=0,c2=0;
	string s;
	cin >> s;
	for(auto p:s)
        if(p=='(')
           c1++;
        else
            c2++;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            if(c1<n/2)
                s[i]='(',c1++;
            else
                s[i]=')';
        }
    }
    int trsum=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            trsum++;
        else
            trsum--;
        if(trsum<0)
        {
            printf(":(\n");
            return 0;
        }
        if(trsum==0&&i!=s.size()-1)
        {
            printf(":(\n");
            return 0;
        }
    }
    if(trsum!=0)
    {
        printf(":(\n");
        return 0;
    }
    cout << s << endl;
    return 0;
}