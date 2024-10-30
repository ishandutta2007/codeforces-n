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

struct {
    int l1, r1, l2, r2;
    int pl, pr;
}ar[100001];
pair < int, pair < int, int > > pp[500001];
int cnt[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> d;
    REP(i, a){
        cin >> b >> c;
        cin >> ar[i].pl >> ar[i].pr;
        ar[i].l1 = b - c; pp[h++] = mp(b-c, mp(0, ar[i].pl));
        ar[i].r1 = b - 1; pp[h++] = mp(b-1, mp(2, ar[i].pl));
        ar[i].l2 = b + 1; pp[h++] = mp(b+1, mp(0, ar[i].pr));
        ar[i].r2 = b + c; pp[h++] = mp(b+c, mp(2, ar[i].pr));
    }
    REP(i, d){
        cin >> b >> c;
        pp[h++] = mp(b, mp(1, c));
    }
    sort(pp, pp + h);
    double res = 0;
    REP(i, h){
        if(pp[i].yy.xx == 0){
            cnt[100 - pp[i].yy.yy]++;
        }
        else if(pp[i].yy.xx == 1){
            double p = 1.0;
            REP(j, 101) if(cnt[j]) p *= pow((double)j/100.0, cnt[j]);
            res += p * (double)pp[i].yy.yy;
        } else {
            cnt[100 - pp[i].yy.yy]--;
        }
    }
    cout << fixed << setprecision(8) << res << endl;
}