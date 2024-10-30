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
#define PI         2.0*acos(0.0)
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

double dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    if(a+b == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= a; i++){
        dp[i][0] = 1.0;
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            double p = (double)i / (double)(i+j);
            double q = (double)(j-1) / (double)(i+j-1);
            dp[i][j] = p;
            if(j == 1)continue;
            double r = (double)(i) / (double)(i+j-2);
//            if(j == b) cout << p << " " << q << " " << r << endl;
            if(j > 1)dp[i][j] += (1.0 - p)*q*r*dp[i-1][j - 2];
            r = (double)(j-2) / (double)(i+j-2);
            if(j > 2)dp[i][j] += (1.0 - p)*q*r*dp[i][j - 3];
        }
    }
    cout << fixed << setprecision(10) << dp[a][b] << endl;
}