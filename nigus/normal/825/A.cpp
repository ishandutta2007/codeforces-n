#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    ll now = 0;
    string s;
    cin >> s;
    for(ll c1 = 0; c1 < n; c1++){
        if(s[c1] == '0'){
            cout << now;
            now = 0;
        }
        else{
            now++;
        }
    }
    cout << now;

    return 0;
}