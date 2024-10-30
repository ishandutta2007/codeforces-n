#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
int A[200011];
VI G[200011];

set<int> B[200011];
int X[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI que;
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) {
	    que.push_back(*e);
	    G[*e].erase(find(G[*e].begin(), G[*e].end(), v));
	}
    }

    int ans = 0;
    REP (i, N) {
	int v = que[N-1-i];
	bool good = true;
	B[v].insert(0);

	EACH (e, G[v]) if (good) {

	    if (B[*e].size() > B[v].size()) {
		swap(B[*e], B[v]);
		swap(X[*e], X[v]);
	    }

	    EACH (f, B[*e]) {
		if (B[v].find(*f ^ X[*e] ^ X[v] ^ A[v]) != B[v].end()) {
		    good = false;
		}
	    }

	    EACH (f, B[*e]) {
		B[v].insert(*f ^ X[*e] ^ X[v]);
	    }
	    B[*e].clear();
	}

// 	eprintf("[%d] ", v+1);
// 	EACH (e, B[v]) eprintf("%d ", A[v] ^ *e);
// 	eprintf("\n");

	X[v] ^= A[v];
	if (!good) {
	    ans++;
	    B[v].clear();
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}