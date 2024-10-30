#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
string A, B;
char buf[100011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", buf);
    A = buf;
    scanf("%s", buf);
    B = buf;

    bool yes = true;

    REP (i, N) {
	if (A[i] > B[i]) yes = false;
    }

    if (yes) {
	int ans = 0;

	REP (c, 20) {
	    int to = 1000;
	    REP (i, N) if (A[i] - 'a' == c && A[i] < B[i]) {
		amin(to, (int)B[i]);
	    }
	    if (to != 1000) {
		ans++;
		REP (i, N) if (A[i] - 'a' == c && A[i] < B[i]) {
		    A[i] = to;
		}
	    }
	}

	printf("%d\n", ans);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}