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

int N;
int A[300011];

bool check(int i) {
    if (1 <= i && i+1 < N) {
	if (A[i-1] < A[i] && A[i] > A[i+1]) return true;
	if (A[i-1] > A[i] && A[i] < A[i+1]) return true;
    }
    return false;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int cnt = 0;
    for (int i=1; i+1<N; i++) {
	cnt += check(i);
    }

    int ans = cnt;
    for (int i=1; i+1<N; i++) {
	int tmp = cnt;
	tmp -= check(i-1);
	tmp -= check(i);
	tmp -= check(i+1);

	int bk = A[i];
	A[i] = A[i-1];
	amin(ans, tmp + check(i-1) + check(i) + check(i+1));
	A[i] = A[i+1];
	amin(ans, tmp + check(i-1) + check(i) + check(i+1));
	A[i] = bk;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}