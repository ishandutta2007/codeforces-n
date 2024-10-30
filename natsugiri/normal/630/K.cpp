#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }


int a[] = { 2, 3, 5, 7 };
int main() {
    LL N;
    scanf("%lld", &N);
    LL ans = 0;
    REP (S, 1<<4) {
	LL d = 1;
	REP (i, 4) if (S & (1<<i)) d *= a[i];
	if (__builtin_popcountll(S) & 1) ans -= N/d;
	else ans += N/d;
    }

    printf("%lld\n", ans);

    return 0;
}