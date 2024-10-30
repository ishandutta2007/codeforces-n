#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N, K;
int A[200011];
const int MAX = 10000011;
int min_factor[MAX];
vector<int>prime;
void make_prime() {
    assert("Call once" && prime.empty());
    for (int i=2; i<MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i*i<MAX; i++) {
	if (min_factor[i] == 0) {
	    min_factor[i] = i;
	    for (int j=i*i; j<MAX; j+=i)
		if (min_factor[j] == 0) min_factor[j] = i;
	}
    }
    for (int i=2; i<MAX; i++) {
	if (min_factor[i] == 0) min_factor[i] = i;
	if (min_factor[i] == i) prime.push_back(i);
    }
}

LL prime_factor(LL n) {
    assert(n <= (LL)MAX * MAX);
    LL ret = 1;
    REP (i, prime.size()) {
	if (n < MAX) break;
	if (n < (LL)prime[i] * prime[i]) break;
	int cnt = 0;
	while (n % prime[i] == 0) {
	    n /= prime[i];
	    cnt++;
	}
	if (cnt & 1) ret *= prime[i];
    }
    if (MAX <= n) {
	ret *= n;
    } else {
	while (1 < n) {
	    int p = min_factor[n], cnt = 0;
	    while (n % p == 0) { n /= p, cnt++; }
	    if (cnt & 1) ret *= p;
	}
    }
    return ret;
}

int dp[200011];

int prv[10000011];

const int INF = 0x3f3f3f3f;
const int INVALID = 0xc0c0c0c0;
const int LIMIT = 45;
int buf[2][LIMIT][21];
int (*cur)[21] = buf[0];
int (*nxt)[21] = buf[1];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	scanf("%d", A+i);
	A[i] = prime_factor(A[i]);
    }

    set<int> se;
    REP (i, N) {
	auto it = se.lower_bound(A[i]);
	if (it != se.end() && *it == A[i]) {
	    se.clear();
	    se.insert(A[i]);
	} else {
	    se.insert(it, A[i]);
	}

	if (se.size() == 1u) {
	    dp[i+1] = dp[i] + 1;
	} else {
	    dp[i+1] = dp[i];
	}
    }


    memset(cur, 0xc0, sizeof buf[0]);
    cur[0][0] = 0;

    REP (i, N) prv[A[i]] = -1;

    REP (i, N) {
	memset(nxt, 0xc0, sizeof buf[0]);

	REP (a, LIMIT) REP (k, K+1) if (cur[a][k] != INVALID) {
	    LL score = dp[i] - a;
	    LL b = dp[i+1] - score;

	    if (0 <= b && b < LIMIT) {
		if (cur[a][k] < i && cur[a][k] <= prv[A[i]]) {
		    if (k < K) {
			amax(nxt[b][k+1], cur[a][k]);
		    }
		} else {
		    amax(nxt[b][k], cur[a][k]);
		}
	    }

	    b = dp[i+1] - (score + 1);
	    if (0 <= b && b < LIMIT) {
		amax(nxt[b][k], i);
	    }
	}

	swap(cur, nxt);
	prv[A[i]] = i;
    }

    int ans = INF;
    REP (a, LIMIT) REP (k, K+1) if (cur[a][k] != INVALID) {
	int g = dp[N] - a + 1;
	amin(ans, g);
    }

    printf("%d\n", ans);
}

int main() {
    make_prime();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}