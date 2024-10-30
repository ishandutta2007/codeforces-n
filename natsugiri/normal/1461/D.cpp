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

int N, Q;
int A[100011];
LL sums[100011];
vector<pair<int, int> > stk;
vector<LL> X;

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    REP (i, N) sums[i+1] = sums[i] + A[i];

    stk.clear();
    stk.emplace_back(0, N);
    X.clear();

    while (!stk.empty()) {
	int l = stk.back().first;
	int r = stk.back().second;
	stk.pop_back();

	X.push_back(sums[r] - sums[l]);
	if (A[l] == A[r-1]) continue;
	int mid = (A[l] + A[r-1]) / 2;
	int k = upper_bound(A+l, A+r, mid) - A;
	stk.emplace_back(l, k);
	stk.emplace_back(k, r);
    }
    sort(X.begin(), X.end());
    REP ($, Q) {
	LL s;
	scanf("%lld", &s);
	auto it = lower_bound(X.begin(), X.end(), s);
	if (it == X.end() || *it != s) puts("No");
	else puts("Yes");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}