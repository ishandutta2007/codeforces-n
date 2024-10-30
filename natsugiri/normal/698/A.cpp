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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N;
int A[111];
int dp[111][3];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    REP (i, N) {
	REP (j, 3) amin(dp[i+1][0], dp[i][j] + 1);

	if (A[i] & 1) {
	    amin(dp[i+1][1], dp[i][0]);
	    amin(dp[i+1][1], dp[i][2]);
	}

	if (A[i] & 2) {
	    amin(dp[i+1][2], dp[i][0]);
	    amin(dp[i+1][2], dp[i][1]);
	}
    }

    int ans = dp[N][0];
    REP (j, 3) amin(ans, dp[N][j]);
    printf("%d\n", ans);



    return 0;
}