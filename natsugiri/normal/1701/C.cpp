#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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

int N, M;
int A[200011];

int C[200011];
bool fix[200011];

bool ok(int mid) {
    memset(C, 0, sizeof (C[0]) * N);
    memset(fix, 0, sizeof (bool) * M);

    REP (i, M) {
	if (C[A[i]] + 1 <= mid) {
	    C[A[i]]++;
	    fix[i] = true;
	}
    }

    int k = 0;
    REP (i, M) if (!fix[i]) {
	while (k < N && C[k] + 2 > mid) k++;
	if (k == N) return false;
	C[k] += 2;
    }
    return true;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d", A+i), A[i]--;

    int lo = 0, hi = 1;
    while (!ok(hi)) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }
    printf("%d\n", hi);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}