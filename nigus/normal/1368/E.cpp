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

const int MAXN = 300001;

bool mark[MAXN] = {0};
bool good[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;

    rep(c4,0,T){
        cin >> n >> m;

       // n = 200000;
      //  m = 199999;

        vector<vi> child(n, vi());
        rep(c1,0,m){
            cin >> a >> b;
           // a = c1+1;
          //  b = c1+2;
            a--;
            b--;
            child[b].push_back(a);
        }

        ll ans = 0;

        rep(c1,0,n){
            mark[c1] = 0;
            good[c1] = 0;
        }

        rep(c1,0,n){
            bool bad = 0;
            trav(i,child[c1]){
                trav(j,child[i]){
                    if(mark[i] && mark[j])bad = 1;
                }
            }

            if(!bad){
                mark[c1] = 1;
                ans++;
            }
        }

        cout << n-ans << "\n";
        rep(c1,0,n){
            if(!mark[c1]){
                cout << c1+1 << " ";
            }
        }cout << "\n";


    }


    return 0;
}