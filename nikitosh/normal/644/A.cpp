#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

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

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""       

const int MAXN = 105;

int c[MAXN][MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (n > a * b)
	{
		puts("-1");
		return 0;
	}
	if (b % 2 == 1)
	{
		int pos = 1;
		forn (i, a)
			forn (j, b)
				if (pos <= n)
					c[i][j] = pos++;
	}
	else
	{
	 	int pos = 1;
	 	forn (i, a)
	 	{
	 		if (i % 2 == 0)
	 		{
	 			forn (j, b)
					if (pos <= n)
						c[i][j] = pos++;
			}
			else
	 		{
	 			fornr (j, b)
					if (pos <= n)
						c[i][j] = pos++;
			}
		}
	}
	forn (i, a)
	{
		forn (j, b)
			printf("%d ", c[i][j]);
		puts("");
	}
	return 0;
}