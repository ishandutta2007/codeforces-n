#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	UL N;
	UL S[50];
	UL T; scanf("%u", &T);
	while (T--) {
		scanf("%u", &N);
		rep(i, N) scanf("%u", S + i);
		UL ans = 1000000;
		sort(S, S + N);
		rep(i, N - 1) ans = min(ans, S[i + 1] - S[i]);
		printf("%u\n", ans);
	}
	return 0;
}