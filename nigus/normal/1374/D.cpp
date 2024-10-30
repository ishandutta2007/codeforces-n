#pragma GCC optimize("O3")   //
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 500001;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        vl A(n);
        map<ll,ll> M;
        ll ma = 0;
        rep(c1,0,n){
            cin >> A[c1];
            A[c1] %= k;
            A[c1] = (k-A[c1])%k;
            if(A[c1] != 0){
                if(M.find(A[c1]) == M.end()){
                    M[A[c1]] = A[c1];
                }
                else{
                    M[A[c1]] += k;
                }
                ma = max(ma, M[A[c1]]);
            }
        }
        if(ma > 0)ma++;
        cout << ma << "\n";
    }

    return 0;
}