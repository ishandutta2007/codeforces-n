#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
VI G[2011];
int par[2011];
int dpE[2011];
int dp1[2011];
int dp2[2011];

const int INF = 1<<29;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    int ans = 0;
    memset(dpE, 0x3f, sizeof (int) * N);
    memset(dp1, 0x3f, sizeof (int) * N);
    memset(dp2, 0x3f, sizeof (int) * N);

    if (N <= 3) {
	ans = N-1;
    } else {
	int root = 0;
	REP (i, N) if (G[i].size() == 1u) {
	    root = i;
	    break;
	}

	VI que;
	que.push_back(root);
	par[root] = root;

	REP (i, N) {
	    int v = que[i];
	    EACH (e, G[v]) if (*e != par[v]) {
		par[*e] = v;
		que.push_back(*e);
		G[*e].erase(find(G[*e].begin(), G[*e].end(), v));
	    }
	}

	REP (i, N) {
	    int v = que[N-1-i];
	    if (G[v].empty()) {
		dpE[v] = 0;
		dp1[v] = dp2[v] = 1;
	    } else if (G[v].size() == 1u) {
		int x = G[v][0];

		dpE[v] = dpE[x];
		dp1[v] = dp1[x];
		dp2[v] = dp2[x];
	    } else {
		dpE[v] = INF;

		int sum = 0;
		EACH (e, G[v]) {
		    sum += dp1[*e];
		}

		dp1[v] = sum;
		EACH (e, G[v]) {
		    amin(dp1[v], sum - dp1[*e] + dpE[*e]);
		}

		dp2[v] = sum;
	    }
	}

	int x = G[root][0];
	ans = INF;
	amin(ans, dpE[x] + 1);
	amin(ans, dp1[x] + 1);
	amin(ans, dp2[x]);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}