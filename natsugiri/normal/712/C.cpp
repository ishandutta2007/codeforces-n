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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int X, Y;
int main() {
    scanf("%d%d", &X, &Y);

    int A[3] = { Y, Y, Y };
    int ans = 0;
    while (true) {
	sort(A, A+3);
	if (A[0] == X) break;
	ans++;

	A[0] = min(X, A[1] + A[2] - 1);
    }

    printf("%d\n", ans);


    return 0;
}