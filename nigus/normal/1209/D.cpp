#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 200001;
vector<vi> C(MAXN,vi());


bool mark[MAXN] = {0};

void dfs(ll i){
    mark[i] = 1;
    rep(c1,0,sz(C[i])){
        int a = C[i][c1];
        if(!mark[a])dfs(a);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    c = 0;
    rep(c1,0,n){
        if(!mark[c1]){
            dfs(c1);
            c++;
        }
    }
    cout << m-n+c << "\n";

    return 0;
}