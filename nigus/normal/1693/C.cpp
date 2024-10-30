#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
 
const ll MAXN = 2000006;

vector<vi> C(MAXN, vi());
vector<vi> C2(MAXN, vi());

set<pii> S;
bool done[MAXN] = {0};
int fakedeg[MAXN] = {0};
int maxp[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d,e;
    
    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C2[b].push_back(a);
    }

    rep(c1,0,n){
        fakedeg[c1] = sz(C[c1]);
        maxp[c1] = fakedeg[c1] + big;
    }
    fakedeg[n-1] = 0;
    maxp[n-1] = 0;
    rep(c1,0,n){
        S.insert({maxp[c1], c1});
    }
    int ans = -1;
    rep(_,0,n){
        pii p = *(S.begin());
        S.erase(p);
        int i = p.second;
        int d = p.first;
    //    cerr << i+1 << " " << d << "\n";
        if(i == 0)ans = d;
        done[i] = 1;
        trav(y, C2[i]){
            if(!done[y]){
                int d2 = maxp[y];
                S.erase({d2, y});
                fakedeg[y]--;
                maxp[y] = min(maxp[y], d+1+fakedeg[y]);
                S.insert({maxp[y], y});
            }
        }

    }
    cout << ans << "\n";

 
    return 0;
}