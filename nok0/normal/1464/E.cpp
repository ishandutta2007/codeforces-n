/**
 *	author: nok0
 *	created: 2021.06.17 11:01:33
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#pragma region Macros
// rep macro
#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)

// name macro
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

// input macro
template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}
#if __has_include(<atcoder/all>)
std::istream &operator>>(std::istream &is, atcoder::modint998244353 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
std::istream &operator>>(std::istream &is, atcoder::modint1000000007 &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::static_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
#endif
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)

// output-macro
template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
#if __has_include(<atcoder/all>)
std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &a) { return os << a.val(); }
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<m> &a) { return os << a.val(); }
template <int m>
std::ostream &operator<<(std::ostream &os, const atcoder::dynamic_modint<m> &a) { return os << a.val(); }
#endif
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}

//debug macro
namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  // namespace debugger
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif

// vector macro
template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}

// math macro
template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
// modpow
long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}

// others
struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

#pragma region datastructure Range Set
#include <cassert>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

template <class T>
struct RangeSet {
private:
	const T TINF = std::numeric_limits<T>::max() / 2;
	T sum;
	std::set<std::pair<T, T>> st;

public:
	RangeSet() : sum(0) {
		st.emplace(-TINF, -TINF);
		st.emplace(TINF, TINF);
	}

	//[l, r) is covered?
	bool covered(const T l, const T r) {
		assert(l <= r);
		if(l == r) return true;
		auto itr = prev(st.upper_bound({l, TINF}));
		return itr->first <= l and r <= itr->second;
	}

	//[x, x + 1) is covered?
	bool covered(const T x) { return covered(x, x + 1); }

	//return section which covers[l, r)
	//if not exists, return[-TINF, -TINF)
	std::pair<T, T> covered_by(const T l, const T r) {
		assert(l <= r);
		if(l == r) return {-TINF, -TINF};
		auto itr = prev(st.upper_bound({l, TINF}));
		if(itr->first <= l and r <= itr->second) return *itr;
		return {-TINF, -TINF};
	}

	//return section which covers[x, x + 1)
	//if not exists, return[-TINF, -TINF)
	std::pair<T, T> covered_by(const T x) { return covered_by(x, x + 1); }

	//insert[l, r), and return increment
	T insert(T l, T r) {
		assert(l <= r);
		if(l == r) return T(0);
		auto itr = prev(st.upper_bound({l, TINF}));
		if(itr->first <= l and r <= itr->second) return T(0);
		T sum_erased = T(0);
		if(itr->first <= l and l <= itr->second) {
			l = itr->first;
			sum_erased += itr->second - itr->first;
			itr = st.erase(itr);
		} else
			itr = next(itr);
		while(r > itr->second) {
			sum_erased += itr->second - itr->first;
			itr = st.erase(itr);
		}
		if(itr->first <= r) {
			sum_erased += itr->second - itr->first;
			r = itr->second;
			st.erase(itr);
		}
		st.emplace(l, r);
		sum += r - l - sum_erased;
		return r - l - sum_erased;
	}

	//insert[x, x + 1), and return increment
	T insert(const T x) { return insert(x, x + 1); }

	// erase [l, r), and return decrement
	T erase(const T l, const T r) {
		assert(l <= r);
		if(l == r) return T(0);
		auto itr = prev(st.upper_bound({l, TINF}));
		if(itr->first <= l and r <= itr->second) {
			if(itr->first < l) st.emplace(itr->first, l);
			if(r < itr->second) st.emplace(r, itr->second);
			st.erase(itr);
			sum -= r - l;
			return r - l;
		}

		T ret = T(0);
		if(itr->first <= l and l < itr->second) {
			ret += itr->second - l;
			if(itr->first < l) st.emplace(itr->first, l);
			itr = st.erase(itr);
		} else
			itr = next(itr);
		while(itr->second <= r) {
			ret += itr->second - itr->first;
			itr = st.erase(itr);
		}
		if(itr->first < r) {
			ret += r - itr->first;
			st.emplace(r, itr->second);
			st.erase(itr);
		}
		sum -= ret;
		return ret;
	}

	// erase [x, x + 1), and return decrement
	T erase(const T x) { return erase(x, x + 1); }

	int size() const { return (int)st.size() - 2; }

	T mex(const T x = 0) const {
		auto itr = prev(st.upper_bound({x, TINF}));
		if(itr->first <= x and x < itr->second)
			return itr->second;
		else
			return x;
	}

	T sum_all() const { return sum; }

	std::set<std::pair<T, T>> get() const {
		std::set<std::pair<T, T>> res;
		for(auto &p : st) {
			if(std::abs(p.first) == TINF) continue;
			res.emplace(p.first, p.second);
		}
		return res;
	}

	void dump() const {
		std::cout << "Rangeset:";
		for(auto &p : st) {
			if(std::abs(p.first) == TINF) continue;
			std::cout << "[" << p.first << "," << p.second << "),";
		}
		std::cout << '\n';
	}
};
#pragma endregion

//ModInt
template <const int &mod>
struct ModInt {
private:
	int x;

public:
	ModInt() : x(0) {}

	ModInt(long long x_) {
		if((x = x_ % mod + mod) >= mod) x -= mod;
	}

	int val() const { return x; }

	static int get_mod() { return mod; }

	constexpr ModInt &operator+=(ModInt rhs) {
		if((x += rhs.x) >= mod) x -= mod;
		return *this;
	}

	constexpr ModInt &operator-=(ModInt rhs) {
		if((x -= rhs.x) < 0) x += mod;
		return *this;
	}

	constexpr ModInt &operator*=(ModInt rhs) {
		x = (unsigned long long)x * rhs.x % mod;
		return *this;
	}

	constexpr ModInt &operator/=(ModInt rhs) {
		x = (unsigned long long)x * rhs.inv().x % mod;
		return *this;
	}

	constexpr ModInt operator-() const noexcept { return -x < 0 ? mod - x : -x; }

	constexpr ModInt operator+(ModInt rhs) const noexcept { return ModInt(*this) += rhs; }

	constexpr ModInt operator-(ModInt rhs) const noexcept { return ModInt(*this) -= rhs; }

	constexpr ModInt operator*(ModInt rhs) const noexcept { return ModInt(*this) *= rhs; }

	constexpr ModInt operator/(ModInt rhs) const noexcept { return ModInt(*this) /= rhs; }

	constexpr ModInt &operator++() {
		*this += 1;
		return *this;
	}

	constexpr ModInt operator++(int) {
		*this += 1;
		return *this - 1;
	}

	constexpr ModInt &operator--() {
		*this -= 1;
		return *this;
	}

	constexpr ModInt operator--(int) {
		*this -= 1;
		return *this + 1;
	}

	bool operator==(ModInt rhs) const { return x == rhs.x; }

	bool operator!=(ModInt rhs) const { return x != rhs.x; }

	bool operator<=(ModInt rhs) const { return x <= rhs.x; }

	bool operator>=(ModInt rhs) const { return x >= rhs.x; }

	bool operator<(ModInt rhs) const { return x < rhs.x; }

	bool operator>(ModInt rhs) const { return x > rhs.x; }

	ModInt inv() {
		int a = x, b = mod, u = 1, v = 0, t;
		while(b > 0) {
			t = a / b;
			std::swap(a -= t * b, b);
			std::swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(long long n) const {
		ModInt ret(1), mul(x);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	ModInt sqrt() const {
		if(x <= 1) return x;
		int v = (mod - 1) / 2;
		if(pow(v) != 1) return -1;
		int q = mod - 1, m = 0;
		while(~q & 1) q >>= 1, m++;
		std::mt19937 mt;
		ModInt z = mt();
		while(z.pow(v) != mod - 1) z = mt();
		ModInt c = z.pow(q), t = pow(q), r = pow((q + 1) / 2);
		for(; m > 1; m--) {
			ModInt tmp = t.pow(1 << (m - 2));
			if(tmp != 1) r = r * c, t = t * c * c;
			c = c * c;
		}
		return std::min(r.x, mod - r.x);
	}

	friend std::ostream &operator<<(std::ostream &s, ModInt<mod> a) {
		s << a.x;
		return s;
	}

	friend std::istream &operator>>(std::istream &s, ModInt<mod> &a) {
		s >> a.x;
		return s;
	}
};

//Modulo Calculation
static int MOD = 998244353;
using mint = ModInt<MOD>;

#pragma region datastructure Matrix
#include <cassert>
#include <iostream>
#include <vector>

template <class T>
struct Matrix {
private:
	std::vector<std::vector<T>> A;

	static Matrix I(size_t n) {
		Matrix mat(n);
		for(int i = 0; i < n; i++) mat[i][i] = 1;
		return mat;
	}

public:
	Matrix() = default;

	Matrix(std::vector<std::vector<T>> &vvec) { A = vvec; }

	Matrix(size_t n, size_t m) : A(n, std::vector<T>(m, 0)) {}

	Matrix(size_t n, size_t m, T init) : A(n, std::vector<T>(m, init)) {}

	Matrix(size_t n, std::vector<T> &vec) : A(n, vec) {}

	Matrix(size_t n) : A(n, std::vector<T>(n, 0)) {}

	size_t height() const { return A.size(); }

	size_t width() const { return A[0].size(); }

	inline const std::vector<T> &operator[](int k) const {
		return A[k];
	}

	inline std::vector<T> &operator[](int k) {
		return A[k];
	}

	Matrix &operator+=(const Matrix &B) {
		size_t n = height(), m = width();
		assert(n == B.height() and m == B.width());
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] += B[i][j];
		return *this;
	}

	Matrix &operator-=(const Matrix &B) {
		size_t n = height(), m = width();
		assert(n == B.height() and m == B.width());
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] -= B[i][j];
		return *this;
	}

	Matrix &operator*=(const Matrix &B) {
		size_t n = height(), m = B.width(), p = width();
		assert(p == B.height());
		std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				for(int k = 0; k < p; k++)
					C[i][j] += (*this)[i][k] * B[k][j];
		A.swap(C);
		return *this;
	}

	Matrix &operator^=(long long k) {
		Matrix B = Matrix::I(height());
		while(k > 0) {
			if(k & 1) B *= (*this);
			*this *= *this;
			k >>= 1ll;
		}
		A.swap(B.A);
		return *this;
	}

	bool operator==(const Matrix &B) {
		size_t n = height(), m = width();
		if(n != B.height() or m != B.width()) return false;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if((*this)[i][j] != B[i][j]) return false;
		return true;
	}

	Matrix operator+(const Matrix &B) const {
		return (Matrix(*this) += B);
	}

	Matrix operator-(const Matrix &B) const {
		return (Matrix(*this) -= B);
	}

	Matrix operator*(const Matrix &B) const {
		return (Matrix(*this) *= B);
	}

	Matrix operator^(const long long &k) const {
		return (Matrix(*this) ^= k);
	}

	Matrix &operator+=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] += t;
		return *this;
	}

	Matrix &operator-=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] -= t;
		return *this;
	}

	Matrix &operator*=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] *= t;
		return *this;
	}

	Matrix &operator/=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] /= t;
		return *this;
	}

	Matrix operator+(const T &t) const {
		return (Matrix(*this) += t);
	}

	Matrix operator-(const T &t) const {
		return (Matrix(*this) -= t);
	}

	Matrix operator*(const T &t) const {
		return (Matrix(*this) *= t);
	}

	Matrix operator/(const T &t) const {
		return (Matrix(*this) /= t);
	}

	friend std::ostream &operator<<(std::ostream &os, Matrix &p) {
		size_t n = p.height(), m = p.width();
		for(int i = 0; i < n; i++) {
			os << '[';
			for(int j = 0; j < m; j++)
				os << p[i][j] << (j == m - 1 ? "]\n" : ",");
		}
		return (os);
	}

	T determinant() {
		Matrix B(*this);
		size_t n = height(), m = width();
		assert(n == m);
		T ret = 1;
		for(int i = 0; i < n; i++) {
			int idx = -1;
			for(int j = i; j < n; j++)
				if(B[j][i] != 0) idx = j;
			if(idx == -1) return 0;
			if(i != idx) {
				ret *= -1;
				swap(B[i], B[idx]);
			}
			ret *= B[i][i];
			T vv = B[i][i];
			for(int j = 0; j < n; j++) B[i][j] /= vv;
			for(int j = i + 1; j < n; j++) {
				T a = B[j][i];
				for(int k = 0; k < n; k++) {
					B[j][k] -= B[i][k] * a;
				}
			}
		}
		return ret;
	}
};
#pragma endregion

template <class T>
int gauss_jordan(Matrix<T> &mat, bool is_extended = false) {
	int n = mat.height(), m = mat.width();
	int rank = 0;
	for(int col = 0; col < m; col++) {
		if(is_extended and col == m - 1) break;
		int pivot = -1;
		for(int row = rank; row < n; row++) {
			if(mat[row][col] != T(0)) {
				pivot = row;
				break;
			}
		}
		if(pivot == -1) continue;
		std::swap(mat[pivot], mat[rank]);
		T inv = mat[rank][col].inv();
		for(int col2 = 0; col2 < m; col2++)
			mat[rank][col2] *= inv;
		for(int row = 0; row < n; row++) {
			if(row != rank and mat[row][col] != T(0)) {
				T fac = mat[row][col];
				for(int col2 = 0; col2 < m; col2++)
					mat[row][col2] -= mat[rank][col2] * fac;
			}
		}
		rank++;
	}
	return rank;
}

template <class T>
std::vector<T> linear_equation(Matrix<T> mat, const std::vector<T> &b) {
	int n = mat.height(), m = mat.width();
	assert((int)b.size() == n);
	vector<mint> res(m);
	for(int i = 0; i < n; i++) mat[i].push_back(b[i]);
	int rank = gauss_jordan(mat, true);
	for(int row = rank; row < n; row++)
		if(mat[row][m] != T(0)) return {};
	for(int i = 0; i < rank; i++) res[i] = mat[i][m];
	return res;
}

void main_() {
	INT(n, m);
	vector<vector<int>> g(n);
	REP(i, m) {
		INT(u, v);
		--u, --v;
		g[u].pb(v);
	}
	V<> vis(n);
	V<> grundy(n);
	auto dfs = [&](auto dfs, int now) -> void {
		if(vis[now]) return;
		vis[now] = 1;
		RangeSet<int> st;
		for(auto &to : g[now]) {
			dfs(dfs, to);
			st.insert(grundy[to]);
		}
		grundy[now] = st.mex();
	};
	REP(i, n) {
		if(vis[i]) continue;
		dfs(dfs, i);
	}
	const mint inv = mint(1) / (n + 1);
	const int sz = 1 << 9;
	V<> gcnt(sz);
	foa(v, grundy) gcnt[v]++;
	Matrix<mint> mat(sz);
	vector<mint> b(sz, inv);
	b[0] = 0;
	REP(i, sz) { mat[i][i] = 1; }
	REP(i, sz) {
		REP(j, sz) {
			mat[i][i ^ j] -= inv * gcnt[j];
		}
	}
	auto res = linear_equation(mat, b);
	print(res.front());
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) main_();
	return 0;
}