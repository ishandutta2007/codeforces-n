#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 1; I <= (N); ++I)
#define REPP(I, A, B) for (int I = (A); I <= (B); ++I)
#define FOR(I, A, B) for(int I = (A); I >= (B) ; --I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define WI(X) printf("%d ", (X))
#define WII(X, Y) printf("%d %d\n", (X), (Y))
#define WIII(X, Y, Z) printf("%d %d %d\n", (X), (Y), (Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#define str string
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
typedef long long LL;
using namespace std;
void home(){
    freopen("TEST.INP","r",stdin);
 //   freopen("TEST.OUT","w",stdout);
}
const int N=1e6+1, mod=1e9+7;
int n, k;
LL result; PLL a[N];

int main(){
//    home();
    RII(n, k);
    REP(i, n) scanf("%I64d", &a[i].F);
    REP(i, n) scanf("%I64d", &a[i].S);

    LL l = 0, r = int(2e9);
    while(l <= r){

        LL mid = (l + r) / 2;
        //cout << mid << endl;
        LL m = k;
        REP(i, n){
           m += min(a[i].S - a[i].F * mid, 0LL);
           if(m < 0) break;
        }
        if(m < 0) r = mid  - 1;
        else {
            result = max(result, mid);
            l = mid + 1;
        }
    }
    cout << result;
    return 0;
}