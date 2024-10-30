/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

map < pair < int, int >, int > mm;
set < pair < int, int > > S;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	FOR(i, 1, n+1){
		int x; cin >> x;
		if(i == 1){
			S.insert(mp(0, x-1)); mm[mp(0, x-1)] = x;
			S.insert(mp(x+1, mod)); mm[mp(x+1, mod)] = x;
			continue;
		}
		set < pair < int, int > >::iterator it = S.upper_bound(mp(x, mod+1)); it--;
		int l = (*it).xx, r = (*it).yy;
		cout << mm[mp(l, r)] << " ";
		
		mm[mp(l, r)] = 0;
		S.erase(it);
		
		if(l != x){
			S.insert(mp(l, x-1)); mm[mp(l, x-1)] = x;
		}
		if(x != r){
			S.insert(mp(x+1, r)); mm[mp(x+1, r)] = x;
		}
	}
	cout << endl;
}