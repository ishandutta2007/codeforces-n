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

int N, X;
char S[100011];
char W[100011];

bool check() {
    REP (i, N) {
	char c = '0';
	if (i >= X && W[i-X] == '1') c = '1';
	if (i+X < N && W[i+X] == '1') c = '1';

	if (c != S[i]) return false;
    }

    return true;
}

void MAIN() {
    scanf("%s%d", S, &X);
    N = strlen(S);

    REP (i, N) W[i] = '1';
    REP (i, N) if (S[i] == '0') {
	if (i >= X) W[i-X] = '0';
	if (i+X < N) W[i+X] = '0';
    }
    W[N] = 0;

    if (check()) {
	puts(W);
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