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

int ar[401][401], dp[401][402], dp1[401][402], dp2[401][401];
short last[160001][401];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b;
    FOR(i, 1, a + 1){
        FOR(j, 1, b + 1) cin >> ar[i][j];
    }
    FOR(k, 1, b + 1){
        for(int i = 1; i <= a; i++){
            g = 0;
            for(int j = i; j >= 1; j--){
                dp[j][i] = max(dp[j][i], dp[j][i - 1]);
                g = max(g, (LL)last[ ar[i][k] ][j]);
                dp[j][i] = max(dp[j][i], (int)g);
            }
            last[ ar[i][k] ][i] = k;
        }
        for(int i = a; i >= 1; i--){
            g = 0;
            for(int j = i + 1; j <= a; j++){
                dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
                g = max(g, (LL)last[ ar[i][k] ][j]);
                dp1[i][j] = max(dp1[i][j], (int)g);
            }
        }
        for(int i = a; i >= 1; i--){
            for(int j = i; j <= a; j++){
                dp2[i][j] = max(dp2[i][j], dp2[i+1][j]);
                dp2[i][j] = max(dp2[i][j], dp2[i][j - 1]);
                dp2[i][j] = max(dp2[i][j], dp1[i][j]);
                dp2[i][j] = max(dp2[i][j], dp[i][j]);
                f = max(f, (LL)(j-i+1)*(k - dp2[i][j]));
            }
        }
    }
    cout << f << endl;
}