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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000005;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    string s;
    cin >> s;
    n = sz(s);
    ll F[26] ={0};
    rep(c1,0,n){
        F[s[c1]-'a']++;
    }
    vi A;
    rep(c1,0,26){
        if(F[c1] > 0)A.push_back(c1);
    }
    if(sz(A) > 4){
        cout << "No\n";
        return 0;
    }
    if(sz(A) == 4){
        cout << "Yes\n";
        return 0;
    }
    if(sz(A) == 3){
        if(n == 3){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
        return 0;
    }
    if(sz(A) == 2){
        if(min(F[A[0]], F[A[1]]) > 1){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
        return 0;
    }
    cout << "No\n";

    return 0;
}