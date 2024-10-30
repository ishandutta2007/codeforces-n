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

const int MAXN = 300001;

string alfa = "abcdefghijklmnopqrstuvwxyz";

ll r;
ll ssum;
vl current;

string s;

vector<string> ANS;

int tried = 0;

void brute(ll sum, ll i){
    sum %= r;
    if(sz(ANS) == k || tried > 2000000)return;
    if(i == n){
        tried++;
        if(sum == ssum){
            string tmp = "";
            rep(c1,0,n){
                tmp += alfa[current[c1]];
            }
            ANS.push_back(tmp);
        }
        return;
    }

    rep(c1,0,26){
        int j = 26-c1-1;
        current.push_back(j);
        brute((sum*m+ll(j))%r, i+1);
        current.pop_back();
    }
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
        vi P(n);
        string s;
        vector<pii> D, L;
        rep(c1,0,n){
            cin >> a;
            P[c1] = a-1;

        }
        cin >> s;
        int disliked = 0;
        rep(c1,0,n){
            if(s[c1] == '0'){
                D.push_back({P[c1], c1});
                disliked++;
            }
            else{
                L.push_back({P[c1], c1});
            }
        }
        sort(all(D));
        sort(all(L));
        int liked = n-disliked;
        vi ANS(n);
        rep(c1,0,disliked){
            ANS[D[c1].second] = c1+1;
        }
        rep(c1,0,liked){
            ANS[L[c1].second] = c1+disliked+1;
        }
        trav(y, ANS){
            cout << y << " ";
        }cout << "\n";
    }

    return 0;
}