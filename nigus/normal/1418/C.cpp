#pragma GCC optimize("O3")

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

const int MAXN = 200001;

int DP[MAXN][2] = {0};
int DPC[MAXN][2] ={0};
int cc = 0;

bool A[MAXN] = {0};

int dp(int i, bool turn){
    if(i >= n)return 0;
    if(DPC[i][turn] == cc)return DP[i][turn];
    int ans = (turn&A[i]) + dp(i+1, turn^1);
    if(i < n-1){
        ans = min(ans, (turn&A[i]) + (turn&A[i+1]) + dp(i+2,turn^1));
    }
    DPC[i][turn] = cc;
    DP[i][turn] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        rep(c1,0,n){
            cin >> A[c1];
        }
        cc++;
        int res = dp(0,1);
        cout << res << "\n";
    }


    return 0;
}