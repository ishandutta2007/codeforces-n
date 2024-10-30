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
char S[300011];

bool go() {
    if (N % 2) return false;

    int open = 0, close = 0;
    REP (i, N) {
	if (S[i] == '(') open++;
	if (S[i] == ')') close++;
    }

    if (open *2 > N || close * 2 > N) return false;
    REP (i, N) if (S[i] == '?') {
	if (open * 2 < N) { S[i] = '('; open++; }
	else { S[i] = ')'; close++; }
    }

    int depth = 0;
    REP (i, N) {
	if (i && depth == 0) return false;
	if (S[i] == '(') depth++;
	else depth--;
	if (depth < 0) return false;
    }
    return true;
}

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);

    if (go()) puts(S);
    else puts(":(");


}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}