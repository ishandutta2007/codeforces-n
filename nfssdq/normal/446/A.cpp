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

LL ar[100001];
LL inc[100001], de[100001];
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1) cin >> ar[i];
    FOR(i, 1, a + 1){
        if(i == 1) de[i] = 1;
        else {
            if(ar[i - 1] < ar[i]) de[i] = 1 + de[i - 1];
            else de[i] = 1;
        }
    }
    for(int i = a; i >= 1; i--){
        if(i == a) inc[i] = 1;
        else {
            if(ar[i + 1] > ar[i]) inc[i] = 1 + inc[i + 1];
            else inc[i] = 1;
        }
    }
    if(a <= 2) {
        cout << a << endl;
        return 0;
    }
    f = 0;
    for(int i = 2; i < a; i++){
        if(ar[i - 1] < ar[i + 1] - 1) f = max(f, inc[i + 1] + de[i - 1] + 1);
        f = max(f, inc[i]);
        f = max(f, de[i]);
        f = max(f, 1 + inc[i + 1]);
        f = max(f, 1 + de[i - 1]);
    }
    f = max(f, inc[1]);
    f = max(f, 1 + inc[2]);
    f = max(f, de[a]);
    f = max(f, 1 + de[a - 1]);
    cout << f << endl;
}