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

const int MAXN = 200101;

int DP[2][27] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;
    rep(c4,0,T){
        string s;
        cin >>s;
        n = sz(s);
        DP[n%2][26] = 0;
        rep(c1,0,26){
            DP[n%2][c1] = 1;
        }
        for(int c1 = n-1; c1 >= 0; c1--){
            int ch = s[c1]-'a';
            for(int c2 = 0; c2 < 27; c2++){
                int temp = 1+DP[(c1+1)%2][c2];
                if(ch == c2){
                    temp = min(temp, DP[(c1+1)%2][26]);
                }
                if(c2 == 26){
                    temp = min(temp, DP[(c1+1)%2][ch]);
                }

               // cerr << temp << " ";

                DP[c1%2][c2] = temp;
            }//cerr << "\n";
        }
        cout << DP[0][26] << "\n";
    }


    return 0;
}