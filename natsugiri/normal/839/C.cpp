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

int N;
VI G[100111];
double E[100111], B[100111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) {
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end());
	    ord.push_back(*e);
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	if (G[v].size()) {
	    int j = 0;
	    EACH (e, G[v]) B[j++] = E[*e] + 1;
	    while (--j) B[j/2] += B[j];
	    E[v] = B[0] / (double)G[v].size();
	}
    }

    printf("%.12f\n", E[0]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}