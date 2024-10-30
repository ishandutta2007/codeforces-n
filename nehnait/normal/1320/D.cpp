//Author:xht37
#include <bits/stdc++.h>

#define ui unsigned int
#define ll long long
#define ul unsigned ll
#define ld long double

#define pi pair <int, int>
#define fi first
#define se second
#define mp make_pair

#define ls (p << 1)
#define rs (ls | 1)
#define md ((t[p].l + t[p].r) >> 1)

#define vi vector <int>
#define pb push_back
#define pq priority_queue

#define dbg(x) cerr << #x" = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

#define fl(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

using namespace std;

namespace io {
	const int SI = 1 << 21 | 1;
	char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
	int f, t;
	#define gc() (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin), IS == IT ? EOF : *IS++) : *IS++)
	inline void flush() {
		fwrite(OB, 1, OS - OB, stdout), OS = OB;
	}
	inline void pc(char x) {
		*OS++ = x;
		if (OS == OT) flush();
	}
	template <class I>
	inline void rd(I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15), c = gc());
		x *= f;
	}
	template <class I>
	inline void rda(I *a, int &n) {
		for (int i = 1; i <= n; i++) rd(a[i]);
	}
	inline void rds(char *s, int &x) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (x = 0; c >= 33 && c <= 126; s[++x] = c, c = gc());
		s[x+1] = '\0';
	}
	template <class I>
	inline void print(I x, char k = '\n') {
		if (!x) pc('0');
		if (x < 0) pc('-'), x = -x;
		while (x) ch[++t] = x % 10 + '0', x /= 10;
		while (t) pc(ch[t--]);
		pc(k);
	}
	inline void prints(string s) {
		int x = s.length();
		while (t < x) pc(s[t++]);
		pc('\n'), t = 0;
	}
	struct Flush {
		~Flush() {
			flush();
		}
	} flusher;
}
using io::rd;
using io::rda;
using io::rds;
using io::print;
using io::prints;

const int P = 1e9 + 7;

struct modint {
    int x;
    inline modint(int x = 0) : x(x) {}
    inline modint &operator = (int o) { return x = o, *this; }
    inline modint &operator += (modint o) { return x = x + o.x >= P ? x + o.x - P : x + o.x, *this; }
    inline modint &operator -= (modint o) { return x = x - o.x < 0 ? x - o.x + P : x - o.x, *this; }
    inline modint &operator *= (modint o) { return x = 1ll * x * o.x % P, *this; }
    inline modint &operator ^= (ll b) {
        modint a = *this, c;
        if (!~b) b = P - 2;
        c.x = 1 % P;
        while (b) {
            if (b & 1) c *= a;
            a *= a, b >>= 1;
        }
        return x = c.x, *this;
    }
    inline modint &operator /= (modint o) { return *this *= o ^= -1; }
    inline modint &operator += (int o) { return x = x + o >= P ? x + o - P : x + o, *this; }
    inline modint &operator -= (int o) { return x = x - o < 0 ? x - o + P : x - o, *this; }
    inline modint &operator *= (int o) { return x = 1ll * x * o % P, *this; }
    inline modint &operator /= (int o) { modint y = modint(o); return *this *= y ^= -1; }
    template <class I>
    inline friend modint operator + (modint a, I b) { return a += b; }
    template <class I>
    inline friend modint operator - (modint a, I b) { return a -= b; }
    template <class I>
    inline friend modint operator * (modint a, I b) { return a *= b; }
    inline friend modint operator ^ (modint a, ll b) { return a ^= b; }
    template <class I>
    inline friend modint operator / (modint a, I b) { return a /= b; }
    inline friend bool operator == (modint a, int b) { return a.x == b; }
    inline friend bool operator != (modint a, int b) { return a.x != b; }
    inline friend bool operator == (modint a, modint b) { return a.x == b.x; }
    inline friend bool operator != (modint a, modint b) { return a.x != b.x; }
    inline bool operator ! () { return !x; }
    inline modint operator - () { return x ? P - x : 0; }
};
inline void rd(modint &x) { rd(x.x); }
inline void print(modint x, char k = '\n') { print(x.x, k); }

#define Hash pair<modint, modint>
const Hash B = mp(131, 13331);
inline Hash operator + (Hash a, Hash b) { return mp(a.fi + b.fi, a.se + b.se); }
inline Hash operator - (Hash a, Hash b) { return mp(a.fi - b.fi, a.se - b.se); }
inline Hash operator * (Hash a, Hash b) { return mp(a.fi * b.fi, a.se * b.se); }
inline Hash operator + (Hash a, int b) { return mp(a.fi + b, a.se + b); }

const int N = 2e5 + 7;
int n, q, c[N];
char s[N];
Hash h[N][2], p[N];

inline Hash H(int l, int r, int o) {
	return h[r][o] - h[l-1][o] * p[c[r]-c[l-1]];
}

inline Hash hh(int l, int r) {
	return H(l, r, l & 1);
}

int main() {
	rd(n), rds(s, n), rd(q);
	p[0] = mp((modint)1, (modint)1);
	for (int i = 1; i <= n; i++) {
		if (s[i] != '0') h[i][0] = h[i-1][0], h[i][1] = h[i-1][1], c[i] = c[i-1];
		else h[i][0] = h[i-1][0] * B + ('0' + (i & 1)), h[i][1] = h[i-1][1] * B + ('0' + ((i & 1) ^ 1)), c[i] = c[i-1] + 1;
		p[i] = p[i-1] * B;
//		debug("c[%d] = %d\n", i, c[i]);
//		debug("h[%d][%d] = %d %d\n", i, 0, h[i][0].fi.x, h[i][0].se.x);
//		debug("h[%d][%d] = %d %d\n", i, 1, h[i][1].fi.x, h[i][1].se.x);
	}
	while (q--) {
		int l1, l2, len;
		rd(l1), rd(l2), rd(len);
		int r1 = l1 + len - 1, r2 = l2 + len - 1;
//		Hash h1 = hh(l1, r1), h2 = hh(l2, r2);
//		debug("h1 = %d %d\n", h1.fi.x, h1.se.x);
//		debug("h2 = %d %d\n", h2.fi.x, h2.se.x);
		prints(hh(l1, r1) == hh(l2, r2) ? "Yes" : "No");
	}
	return 0;
}