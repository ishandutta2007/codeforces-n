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
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

char p1[101], p2[101], p3[101];
int ar[101][27], a, b, c;
int dp[101][101][101];

int go(int s1, int s2, int s3){
    if(s1 > a || s2 > b)return 0;
    if(dp[s1][s2][s3] != -1)return dp[s1][s2][s3];
    int &res = dp[s1][s2][s3];
    res = 0;
    if(p1[s1 - 1] == p2[s2 - 1]){
        if(ar[s3][p1[s1 - 1] - 'A'] == c)goto pe;
        res = 1 + go(s1 + 1, s2 + 1, ar[s3][p1[s1 - 1] - 'A']);
    }
    pe:
    int l = go(s1 + 1, s2, s3), r = go(s1, s2 + 1, s3);
    if(l > res)res = l;
    if(r > res)res = r;
    return res;
}
void print(int s1, int s2, int s3){
    if(s1 > a || s2 > b)return;
    if(p1[s1 - 1] == p2[s2 - 1]){
        if(ar[s3][p1[s1 - 1] - 'A'] == c)goto pf;
        if(dp[s1][s2][s3] == 1 + go(s1 + 1, s2 + 1, ar[s3][p1[s1 - 1] - 'A']) ){
            cout << p1[s1 - 1];
            print(s1 + 1, s2 + 1, ar[s3][p1[s1 - 1] - 'A']);
            return;
        }
    }
    pf:
    int l = go(s1 + 1, s2, s3), r = go(s1, s2 + 1, s3);
    if(l == dp[s1][s2][s3])print(s1 + 1, s2, s3);
    else print(s1, s2 + 1, s3);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL d,e,f,g,h = 0,x,y,z;
    cin >> p1 >> p2 >> p3;
    a = strlen(p1);
    b = strlen(p2);
    c = strlen(p3);
    REP(i, c)ar[i][p3[0] - 'A'] = 1;
    REP(i, c - 1){
        for(int j = 1; j < c - i - 1; j++){
            d = 0;
            for(int k = j; k <= j + i; k++)if(p3[k] != p3[k - j])d = 1;
            if(d == 0)ar[j + i + 1][p3[i + 1] - 'A'] = max(ar[j + i + 1][p3[i + 1] - 'A'], i + 2);
        }
        ar[i + 1][p3[i + 1] - 'A'] = i + 2;
    }
    memset(dp, -1, sizeof dp);
    d = go(1, 1, 0);
    //cout << d << endl;
    if(d == 0){
        cout << 0 << endl;
        return 0;
    }
    print(1, 1, 0);
}