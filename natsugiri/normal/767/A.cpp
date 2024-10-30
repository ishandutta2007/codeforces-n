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
pair<int, int> P[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", &P[i].first), P[i].second = i;
    sort(P, P+N, greater<pair<int, int> >());
    int pos = 0;
    REP (i, N) {
	VI v;
	while (pos < N && P[pos].second <= i) v.push_back(P[pos++].first);
	rprintf("%d", v.begin(), v.end());
    }

    return 0;
}