#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ios\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
#define VEC(type, name, size)\
    V<type> name(size);\
    IN(name)
#define VVEC(type, name, h, w)\
    VV<type> name(h, V<type>(w));\
    IN(name)
#define INT(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LL(...)\
    ll __VA_ARGS__;\
    IN(__VA_ARGS__)
#define STR(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define CHAR(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define DOUBLE(...)\
    DOUBLE __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LD(...)\
    LD __VA_ARGS__;\
    IN(__VA_ARGS__)
template <class T> void scan(T &a) { cin >> a; }
template <class T> void scan(vector<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
#define ll long long
#define ld long double
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
const ll INF = 1e18;
#pragma endregion

//Modulo Calculation
const int MOD = 1e9 + 7;
// const int MOD = 998244353;

//ModInt
template <int mod>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(ll x_) {
        if ((x = x_ % mod + mod) >= mod) x -= mod;
    }
    ModInt& operator+=(ModInt rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        if ((x -= rhs.x) < 0) x += mod;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (unsigned long long)x * rhs.x % mod;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        x = (unsigned long long)x * rhs.inv().x % mod;
        return *this;
    }
  
    ModInt operator-() const { return -x < 0 ? mod - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    ModInt &operator++ () { *this += 1; return *this;}
    ModInt operator++ (int) { *this += 1; return *this - 1;}
    ModInt &operator-- () { *this -= 1; return *this;}
    ModInt operator-- (int) { *this -= 1; return *this + 1;}
    bool operator==(ModInt rhs) const { return x == rhs.x; }    
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    bool operator<=(ModInt rhs) const { return x <= rhs.x; }
    bool operator>=(ModInt rhs) const { return x >= rhs.x; }
    bool operator<(ModInt rhs) const { return x < rhs.x; }
    bool operator>(ModInt rhs) const { return x > rhs.x; }
    ModInt inv() const { return pow(*this, mod - 2); }
  
    friend ostream& operator<<(ostream& s, ModInt<mod> a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt<mod>& a) {
        s >> a.x;
        return s;
    }
};
using mint = ModInt<MOD>;

//

const int MAX = 1000010;
mint fac[MAX],finv[MAX],inv[MAX];
//
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*(mint)i;
        inv[i]=(mint)MOD-inv[MOD%i]*(mint)(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}

//nCk
mint COM(int n,int k){
    if(n < k or n < 0 or k < 0)return 0;
    return fac[n]*finv[k]*finv[n-k];
}

//nPk
mint PER(int n, int k){
    if(n < k or n < 0 or k < 0) return 0;
    return fac[n] / fac[n-k];
}

//nHk
mint HOM(int n, int k) {return COM(n+k-1, k);};


int main(){
    COMinit();
    ios;
    INT(n);
    mint res = fac[n] - pow((mint)2, n - 1);
    cout << res << endl;
}