#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
char S[200011];
int sums[200011];

int prefix_max[200011];
int prefix_min[200011];
int suffix_max[200011];
int suffix_min[200011];


void MAIN() {
    scanf("%d%d", &N, &M);
    scanf("%s", S);

    REP (i, N) sums[i+1] = sums[i] + (S[i] == '+'? 1: -1);

    REP (i, N) {
	prefix_max[i+1] = max(prefix_max[i], sums[i+1]);
	prefix_min[i+1] = min(prefix_min[i], sums[i+1]);
    }

    suffix_max[N] = suffix_min[N] = 0;
    for (int i=N; i--;) {
	suffix_max[i] = max(suffix_max[i+1], sums[i] - sums[N]);
	suffix_min[i] = min(suffix_min[i+1], sums[i] - sums[N]);
    }

    REP ($, M) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;

	int low = 0, high = 0, all = 0;
	all += sums[l];
	all += sums[N] - sums[r];

	amax(high, prefix_max[l]);
	amin(low, prefix_min[l]);
	amax(high, all + suffix_max[r]);
	amin(low, all + suffix_min[r]);

	int ans = high - low + 1;
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}