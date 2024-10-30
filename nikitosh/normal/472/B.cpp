#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

multiset <int> s;
int n, k, a[2005], ans;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s.insert(a[i] - 1);
	}
	while(1)
	{
		ans += 2 * *s.rbegin();
		for (int i = 0; i < k; i++)
		{
		    if (s.size() == 0)
		    {
		    	printf("%d\n", ans);
		    	return 0;
		    }
		    multiset<int>::iterator it = s.end();
		    it--;
			s.erase(it);
		}
		if (s.size() == 0)
		    {
		    	printf("%d\n", ans);
		    	return 0;
		    }
		    
	}
	    
    return 0;
}