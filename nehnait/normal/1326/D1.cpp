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
	inline void rda(I *a, int n) {
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

const int N = 1e6 + 7;
int n, m;
char s[N], t[N];

inline int work(char *s, int n) {
	string ss = "$#";
	vi p;
	for (int i = 1; i <= n; i++) ss += s[i], ss += "#";
	p.pb(1);
	int mx = 0, id = 0, ans = 1;
	for (int i = 1; i < (int)ss.length(); i++) {
		p.pb(mx > i ? min(p[2*id-i], mx - i) : 1);
		while (i + p[i] < (int)ss.length() && ss[i+p[i]] == ss[i-p[i]]) ++p[i];
		if (i == p[i]) ans = max(ans, p[i]);
		if (i + p[i] > mx) mx = i + p[i], id = i;
	}
	return ans - 1;
}

inline void solve() {
	rds(s, n);
	int p = 1;
	while (p <= n && s[p] == s[n+1-p]) ++p;
	if (p == n + 1) {
		for (int i = 1; i <= n; i++) putchar(s[i]);
		return puts(""), void();
	}
	m = 0;
	for (int i = p; i <= n + 1 - p; i++) t[++m] = s[i];
	int l = work(t, m);
	reverse(t + 1, t + m + 1);
	int r = work(t, m);
	reverse(t + 1, t + m + 1);
	if (l < r) reverse(t + 1, t + m + 1), swap(l, r);
	for (int i = 1; i < p; i++) putchar(s[i]);
	for (int i = 1; i <= l; i++) putchar(t[i]);
	for (int i = p - 1; i; i--) putchar(s[i]);
	puts("");
}

int main() {
	int T;
	rd(T);
	while (T--) solve();
	return 0;
}