#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
LL A[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    sort(A, A+N);
    LL sum = 0;
    REP (i, N) sum += A[i];
    
    priority_queue<LL> Q;
    Q.push(sum);
    bool yes = true;
    int idx = N-1;

    while (!Q.empty()) {
	LL v = Q.top(); Q.pop();
	if (idx == -1) {
	    yes = false;
	    break;
	} else if (A[idx] == v) {
	    idx--;
	} else if (v == 1 || v < A[idx]) {
	    yes = false;
	    break;
	} else {
	    Q.push(v/2);
	    Q.push(v-v/2);
	}
    }


    if (Q.size()) {
	yes = false;
    }
    if (idx != -1) {
	yes = false;
    }

    puts(yes?"YES":"NO");

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}