#include <bits/stdc++.h>
#define int long long
using namespace std;

template <const int32_t MOD> struct ModInt {
  int32_t x;
  ModInt() : x(0) {}
  ModInt(long long u) : x(u % MOD) {
    if (x < 0)
      x += MOD;
  }
  friend bool operator==(const ModInt &a, const ModInt &b) {
    return a.x == b.x;
  }
  friend bool operator!=(const ModInt &a, const ModInt &b) {
    return a.x != b.x;
  }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.x < b.x; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.x > b.x; }
  friend bool operator<=(const ModInt &a, const ModInt &b) {
    return a.x <= b.x;
  }
  friend bool operator>=(const ModInt &a, const ModInt &b) {
    return a.x >= b.x;
  }
  static ModInt sign(long long k) {
    return ((k & 1) ? ModInt(MOD - 1) : ModInt(1));
  }

  ModInt &operator+=(const ModInt &m) {
    x += m.x;
    if (x >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &m) {
    x -= m.x;
    if (x < 0LL)
      x += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &m) {
    x = (1LL * x * m.x) % MOD;
    return *this;
  }

  friend ModInt operator-(const ModInt &a) {
    ModInt res(a);
    if (res.x)
      res.x = MOD - res.x;
    return res;
  }
  friend ModInt operator+(const ModInt &a, const ModInt &b) {
    return ModInt(a) += ModInt(b);
  }
  friend ModInt operator-(const ModInt &a, const ModInt &b) {
    return ModInt(a) -= ModInt(b);
  }
  friend ModInt operator*(const ModInt &a, const ModInt &b) {
    return ModInt(a) *= ModInt(b);
  }

  static long long fp(long long u, long long k) {
    long long res = 1LL;
    while (k > 0LL) {
      if (k & 1LL)
        res = (res * u) % MOD;
      u = (u * u) % MOD;
      k /= 2LL;
    }
    return res;
  }

  static constexpr int mod() { return MOD; }

  ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
  ModInt inv() {
    assert(x);
    return ModInt(fp(x, MOD - 2));
  }
  ModInt &operator/=(const ModInt &m) { return *this *= ModInt(m).inv(); }
  friend ModInt operator/(const ModInt &a, const ModInt &b) {
    return ModInt(a) *= ModInt(b).inv();
  }

  friend ostream &operator<<(ostream &out, const ModInt &a) {
    return out << a.x;
  }
  friend istream &operator>>(istream &in, ModInt &a) { return in >> a.x; }
};

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
using Mint = ModInt<MOD>;

const int MAXN = 1e6;

Mint fact[MAXN], invFact[MAXN];

void initFact() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = i * fact[i - 1];
  invFact[MAXN - 1] = fact[MAXN - 1].inv();
  for (int i = MAXN - 1; i; --i)
    invFact[i - 1] = invFact[i] * i;
}

Mint binom(int n, int k) {
  if (k < 0 or k > n)
    return 0;
  return fact[n] * invFact[k] * invFact[n - k];
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  initFact();

  int N, M;
  cin >> N >> M;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    cin >> arr[i];
  vector<int> pref(2 * N + 1);
  for (int i = 0; i < 2 * N; ++i)
    pref[i + 1] = pref[i] + arr[i % N];
  int voulu = pref[N];
  if (voulu % 2) {
    cout << Mint(M).fastpow(N) << endl;
    return 0;
  }
  voulu /= 2;

  int nbDiam = 0;
  for (int i = 0; i < N; ++i) {
    int j =
        lower_bound(pref.begin(), pref.end(), voulu + pref[i]) - pref.begin();
    if (pref[j] - pref[i] == voulu)
      nbDiam++;
  }
  assert(nbDiam % 2 == 0);
  nbDiam /= 2;
  Mint sol = 0;
  for (int j = 0; j <= nbDiam; ++j)
    sol += binom(nbDiam, j) * binom(M, j) * fact[j] *
           Mint(M - j).fastpow(N - nbDiam - j) *
           Mint(M - j - 1).fastpow(nbDiam - j);
  cout << sol << endl;
}