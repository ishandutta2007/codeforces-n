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
char S[1011];

void MAIN() {
    scanf("%d%s", &N, S);
    string g = "a";
    while (1) {
	bool ok = true;
	REP (i, N-(int)g.size()+1) {
	    bool same = true;
	    if (g[0] != S[i]) same = false;
	    if (same && g.size() >= 2u && g[1] != S[i+1]) same = false;
	    if (same && g.size() >= 3u && g[2] != S[i+2]) same = false;
	    if (same) {
		ok = false;
		break;
	    }
	}
	if (ok) {
	    puts(g.c_str());
	    return;
	}

	int c = 1;
	for (int i=g.size(); i--;) {
	    if (g[i] == 'z') {
		g[i] = 'a';
	    } else {
		g[i]++;
		c = 0;
		break;
	    }
	}
	if (c) g.push_back('a');
    }

    assert(false);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}