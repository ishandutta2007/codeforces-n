#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define mt make_tuple

#define fi first
#define se second
#define all(c) begin(c), end(c)
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define si(c) (int)(c).size()
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <typename T> vi iota(vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(all(res), 0);
    sort(all(res), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x + y - 1) / y);
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    sort(all(y));
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> vector<S> zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
    return v;
}
// bit 
ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
// int allbit(int n) { return (1 << n) - 1; }
ll allbit(ll n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}

template <class T> pair<T, T> operator-(const pair<T, T> &x, const pair<T, T> &y) { return pair<T, T>(x.fi - y.fi, x.se - y.se); }
template <class T> pair<T, T> operator+(const pair<T, T> &x, const pair<T, T> &y) { return pair<T, T>(x.fi + y.fi, x.se + y.se); }
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }

// template <class T> pair<T, T> &operator+=(pair<T, T> x, const pair<T, T> &y) {
//     x = x + y;
//     return &x;
// }
// template <class T> pair<T, T> &operator-=(pair<T, T> x, const pair<T, T> &y) {
//     x = x - y;
//     return &x;
// }

template <class T> ll operator*(const pair<T, T> &x, const pair<T, T> &y) { return (ll)x.fi * y.fi + (ll)x.se * y.se; }

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    constexpr bool operator<(const edge<T> &rhs) const noexcept { return cost < rhs.cost; }
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return move(res);
}
template <class T> Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return move(res);
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S> void add(Wgraph<S> &G, int x, int y, S c) { G[x].eb(y, c), G[y].eb(x, c); }

#define i128 __int128_t
#define ull unsigned long long int
#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for(auto it = begin(v); it != end(v); ++it) {
        if(it == begin(v))
            os << *it;
        else
            os << " " << *it;
    }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <class S, class T> string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
template <class A> string to_string(A v) {
    if(v.empty()) return "{}";
    string ret = "{";
    for(auto &x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}
string to_string(string s) { return "\"" + s + "\""; }
string to_string(char c) { return string(1, c); }

#ifdef _LOCAL
void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define endl '\n'
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    dump(x)
#else
void dump() {}
template <class Head, class... Tail> void dump(Head head, Tail... tail) {}
#define debug(x)
#endif

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#define drop(s) cout << #s << endl, exit(0)

template <int N> struct ndFORarray {
    std::array<int, N> v;
    ndFORarray(std::array<int, N> v_) : v(v_) {}
    struct ndFORitr {
        const std::array<int, N> &v;
        std::array<int, N> tmp;
        bool is_end;
        ndFORitr(const std::array<int, N> &v_) : v(v_), tmp(), is_end(false) {}
        bool operator!=(const ndFORitr &) const { return !is_end; }
        void operator++() {
            int pos = N - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::array<int, N> &operator*() const { return tmp; }
    };
    ndFORitr begin() const { return ndFORitr(v); }
    ndFORitr end() const { return ndFORitr(v); }
};

struct ndFORvector {
    std::vector<int> v;
    ndFORvector(std::vector<int> v_) : v(v_) {}
    struct ndFORitr {
        const std::vector<int> &v;
        std::vector<int> tmp;
        bool is_end;
        ndFORitr(const std::vector<int> &v_) : v(v_), tmp(v.size(), 0), is_end(false) {}
        bool operator!=(const ndFORitr &) const { return !is_end; }
        void operator++() {
            int pos = v.size() - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::vector<int> &operator*() const { return tmp; }
    };
    ndFORitr begin() const { return ndFORitr(v); }
    ndFORitr end() const { return ndFORitr(v); }
};

auto ndFOR(std::vector<int> v) { return ndFORvector(v); }
template <class... Ts> auto ndFOR(Ts... v) { return ndFORarray<std::tuple_size<std::tuple<Ts...>>::value>({v...}); }
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...); }
};

#pragma endregion

// from https://judge.yosupo.jp/submission/5147
vector<int> prime_sieve(const int N, const int Q = 17, const int L = 1 << 15) {
    using u8 = unsigned char;
    static const int rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
    struct P {
        P(int p) : p(p) {}
        int p;
        int pos[8];
    };
    auto approx_prime_count = [](const int N) -> int { return N > 60184 ? N / (log(N) - 1.1) : max(1., N / (log(N) - 1.11)) + 1; };

    const int v = sqrt(N), vv = sqrt(v);
    vector<bool> isp(v + 1, true);
    for(int i = 2; i <= vv; ++i)
        if(isp[i]) {
            for(int j = i * i; j <= v; j += i) isp[j] = false;
        }

    const int rsize = approx_prime_count(N + 30);
    vector<int> primes = {2, 3, 5};
    int psize = 3;
    primes.resize(rsize);

    vector<P> sprimes;
    size_t pbeg = 0;
    int prod = 1;
    for(int p = 7; p <= v; ++p) {
        if(!isp[p]) continue;
        if(p <= Q) prod *= p, ++pbeg, primes[psize++] = p;
        auto pp = P(p);
        for(int t = 0; t < 8; ++t) {
            int j = (p <= Q) ? p : p * p;
            while(j % 30 != rs[t]) j += p << 1;
            pp.pos[t] = j / 30;
        }
        sprimes.push_back(pp);
    }

    vector<u8> pre(prod, 0xFF);
    for(size_t pi = 0; pi < pbeg; ++pi) {
        auto pp = sprimes[pi];
        const int p = pp.p;
        for(int t = 0; t < 8; ++t) {
            const u8 m = ~(1 << t);
            for(int i = pp.pos[t]; i < prod; i += p) pre[i] &= m;
        }
    }

    const int block_size = (L + prod - 1) / prod * prod;
    vector<u8> block(block_size);
    u8 *pblock = block.data();
    const int M = (N + 29) / 30;

    for(int beg = 0; beg < M; beg += block_size, pblock -= block_size) {
        int end = min(M, beg + block_size);
        for(int i = beg; i < end; i += prod) { copy(pre.begin(), pre.end(), pblock + i); }
        if(beg == 0) pblock[0] &= 0xFE;
        for(size_t pi = pbeg; pi < sprimes.size(); ++pi) {
            auto &pp = sprimes[pi];
            const int p = pp.p;
            for(int t = 0; t < 8; ++t) {
                int i = pp.pos[t];
                const u8 m = ~(1 << t);
                for(; i < end; i += p) pblock[i] &= m;
                pp.pos[t] = i;
            }
        }
        for(int i = beg; i < end; ++i) {
            for(int m = pblock[i]; m > 0; m &= m - 1) { primes[psize++] = i * 30 + rs[__builtin_ctz(m)]; }
        }
    }
    assert(psize <= rsize);
    while(psize > 0 && primes[psize - 1] > N) --psize;
    primes.resize(psize);
    return primes;
}

vector<int> prime_table(int N) {
    auto r = prime_sieve(N);
    vector<int> res(N + 1);
    for(auto e : r) res[e] = 1;
    return res;
}

struct Timer {
  private:
    chrono::high_resolution_clock::time_point start, end;

  public:
    Timer() { set(); }
    void set() { start = chrono::high_resolution_clock::now(); }
    int time() {
        end = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }
    bool before(double T) { return time() < (int)(T * 1000); }
    void print() { cerr << "elapsed time: " << (double)time() / 1000 << " sec" << endl; }
};

struct Random {
  private:
    uint32_t a, b, c, d;

  public:
    Random(uint32_t seed = 517) { set_seed(seed); }
    void set_seed(uint32_t seed) {
        a = seed = 1812433253u * (seed ^ (seed >> 30));
        b = seed = 1812433253u * (seed ^ (seed >> 30)) + 1;
        c = seed = 1812433253u * (seed ^ (seed >> 30)) + 2;
        d = seed = 1812433253u * (seed ^ (seed >> 30)) + 3;
    }
    uint32_t operator()() {
        uint32_t t = (a ^ (a << 11));
        a = b;
        b = c;
        c = d;
        return d = (d ^ (d >> 19)) ^ (t ^ (t >> 8));
    }

    // [0,MAX)
    int operator()(int MAX) { return (uint64_t) operator()() * MAX >> 32; }

    // [L,R)
    uint32_t operator()(int L, int R) { return L + operator()(R - L); }

    // [0,1) 
    double drnd() { return (double)operator()() / (1LL << 32); }

    //  p  true 
    bool prob(const double p) { return (uint32_t)(p * (1LL << 32)) > operator()(); }

    bool coin() { return operator()() < (1 << 31); }

    template <typename T> void shuffle(vector<T> &v) {
        for(int i = v.size() - 1; i; i--) { swap(v[i], v[operator()(i)]); }
    }
} rnd;

int main() {
    Timer timer;
    ll ma = 0;
    INT(n);
    VEC(ll, a, n);
    sort(all(a));
    vpll v;
    auto P = prime_sieve(1000001);
    for(auto e : a) {
        if(empty(v) or v.back().fi != e)
            v.eb(e, 1);
        else
            v.back().se++;
    }
    set<ll> used;
    rep(_, 10) {
        int i = rnd(si(a));
        ll t = a[i];
        if(used.count(t)) continue;
        used.emplace(t);
        ll T = t;
        vll w, p, c;
        for(auto e : P) {
            if(e > T) break;
            if(T % e == 0) {
                p.eb(e), c.eb(0);
                while(T % e == 0) {
                    T /= e;
                    c.back()++;
                }
            }
        }
        if(T > 1) p.eb(T), c.eb(1);
        REC([&](auto &&f, int i, ll now = 1) -> void {
            if(i == si(p))
                w.eb(now);
            else {
                rep2(j, 0, c[i]) {
                    f(i + 1, now);
                    now *= p[i];
                }
            }
        })
        (0);

        sort(all(w));

        vi cnt(si(w));
        for(auto [x, y] : v) { cnt[lb(w, gcd(t, x))] += y; }

        for(auto e : p) {
            rep3(j, si(w) - 1, 0) {
                if(w[j] % e == 0) {
                    int k = j;
                    ll target = w[j] / e;
                    while(w[k] != target) k--;
                    cnt[k] += cnt[j];
                }
            }
        }
        rep(i, si(w)) if(cnt[i] * 2 >= n) chmax(ma, w[i]);
    }
    cout << ma << endl;
}