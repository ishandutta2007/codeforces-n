#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL P, K;

void MAIN() {
    scanf("%lld%lld", &P, &K);
    vector<LL> ans;

    while (1) {
	LL nxt;
	if (0 <= P && P < K) {
	    if (P) ans.push_back(P);
	    break;
	} else if (P < 0) {
	    nxt = (K-P)/K;
	    while (nxt * K >= K-P) nxt--;
	} else {
	    nxt = -(P/K);
	}
	ans.push_back(nxt * K + P);
	P = nxt;
    }

    printf("%d\n", (int)ans.size());
    rprintf("%lld", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}