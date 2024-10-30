#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

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
unsigned long long sqrtu64(unsigned long long n) {
    if (n >= 0xFFFFFFFFULL * 0xFFFFFFFFULL) {
	return 0xFFFFFFFFULL; // maximum return value;
    } else {
	unsigned long long tmp = sqrt((double)n); // < 0xFFFFFFFFULL;
	do { ++tmp; } while (tmp * tmp <= n);
	do { --tmp; } while (tmp * tmp > n);
	return tmp;
    }
}

LL F(LL n) {
    if (n == 0) return 0;

    LL s = sqrtu64(n);
    LL ret = (s-1) * 3;
    ret++;
    if (s * (s+1) <= n) ret++;
    if (s * (s+2) <= n) ret++;
    return ret;
}

void MAIN() {
    LL l, r;
    scanf("%lld%lld", &l, &r);
    LL ans = F(r) - F(l-1);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}