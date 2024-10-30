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



template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

char ar[1001];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    cin >> ar;
    b--;
    c = (a - 1) / 2;
    if(b <= c){
        while(b > 0){
            cout << "LEFT" << endl;
            b--;
        }
    } else {
        while(b < a-1){
            cout << "RIGHT" << endl;
            b++;
        }
    }
    if(b == 0){
        for(int i = 0; i < a; i++){
            cout << "PRINT " << ar[i] << endl;
            if(i < a - 1)cout << "RIGHT" << endl;
        }
    } else {
        for(int i = a - 1; i >= 0; i--){
            cout << "PRINT " << ar[i] << endl;
            if(i > 0) cout << "LEFT" << endl;
        }
    }
}