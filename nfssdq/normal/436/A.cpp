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

pair < int, int > pp[2][2001];

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b;
    c = d = 0;
    FOR(i, 1, a + 1) {
        cin >> e >> f >> g;
        if(e == 0) pp[e][c++] = mp(f, g);
        else pp[e][d++] = mp(f, g);
    }
    sort(pp[0], pp[0] + c);
    sort(pp[1], pp[1] + d);

    int flag[2][2001];
    set0(flag);
    e = 0;
    x = 0;
    LL hi = b;
    while(1){
        f = c;
        if(e == 1) f = d;
        g = 0; h = -1;
        for(int i = 0; i < f; i++){
            if(flag[e][i] == 0 && pp[e][i].yy > g && pp[e][i].xx <= hi){
                g = pp[e][i].yy;
                h = i;
            }
        }
        if(g == 0) break;
        x++;
        hi += g;
        flag[e][h] = 1;
        e ^= 1;
    }

    set0(flag);
    e = 1;
    y = 0;
    hi = b;
    while(1){
        f = c;
        if(e == 1) f = d;
        g = 0; h = -1;
        for(int i = 0; i < f; i++){
            if(flag[e][i] == 0 && pp[e][i].yy > g && pp[e][i].xx <= hi){
                g = pp[e][i].yy;
                h = i;
            }
        }
        if(g == 0) break;
        y++;
        hi += g;
        flag[e][h] = 1;
        e ^= 1;
    }
    cout << max(x, y) << endl;
}