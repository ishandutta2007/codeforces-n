#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int INF = 2e9 + 5, MAX_N = 502;

int a[MAX_N];

int test(int k, int n) {
 	int cnt = 0;
 	forn (i, n) {
 		int l = k / a[i];
 		k -= a[i] * l, cnt += l;
	}
	return cnt;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i]);
	int minn = INF;
	forab (i, 1, n)
		forab (j, i, n) {
			int k = a[i - 1] - 1, l = 0, cnt = 0;
			forn (g, j + 1) {
				int s = k / a[g];
				k -= a[g] * s, l += a[g] * s, cnt += s;
			}
			l += a[j], cnt++;
			if (test(l, n) > cnt)
				minn = min(minn, l);
		}
	if (minn == INF)
		puts("-1");
	else
		printf("%d\n", minn);	
	return 0;
}