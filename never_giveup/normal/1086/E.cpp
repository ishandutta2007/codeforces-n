/*
                     .:*+=%@@@@@@=-.
                 .:=@#@@@#@@#######%==*.
              .-=####@######%*-.....:%##%.
            .*@###########%+:--........-%@-
          .*@##############@+--.........-:%-
        .+##################@==%%%%=+*:----+.
      .-@####################%++%@@@@@=+**%@@*
      .%###################@%%@@@###@%+:--%@@%.
     -@###################@%%%%*::*%++:-----=@+.
    -#####################@%=++++++*:-------.-=:
   .+####################@%++*::-:::--::*:::***=:
   .@#####################%=++*::::-:::++*=##@@#@-
  ..#####################@%%=++**:::::**+%@#@%%##-..
   .%####################@@%=+++*+****::*=@######@.
  .=######################@%%==+==++**+=@%@##@###+:...
  -#######################@@@%%%===++=@@@%=++===*::--...
  -########################@@@@@@@%==%%=++==@@:::::*:--.
..:#########################@@@@@@%%======++++::-..:-.--...
%#############################@###@%%@@%==%=%*----.--.::---.
#############################################*-:*:-:---*---- .
#############################################*--*--:---*---:-.
#############################################+--::--::-*::-::.
###########################################+:*-.---.---.:---*-..
###########################################**:-----------------.
##########################################@::**:--::::::--:::::-
###########################################:--:*:::::::::**::*+*
###########################################=:::***::::::**:::*+*
############################@@@@@@#########@+****::::********+++
############################@%%%%%@@@@@@@###%+***::::::::***+==+
############################@%%%%%%%%%%%@####=+:::-::::-::*+=%%+
#############################@%%%%%%%%%%@#####=::--------:*=%@%+
%###########################@%%%%==%%%%%%@##@#=:------..-:+%@@%=
----------------------------------------------
--------------------------------------------
----------------------------------------------
--------------------------------------------
----------------------------------------------

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/

///YEAH IM THE BEST I'VE EVER WAS

///SO HAPPY

#include <bits/stdc++.h>

#define popcnt(x) __builtin_popcount(x)

#define fr first

#define sc second

#define m_p make_pair

#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()

#define up_bo(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()

#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())

#define popcnt(x) __builtin_popcount(x)

//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;

//gp_hash_table<int, int> table;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

/*char memory[(int)1e8];

char memorypos;

inline void * operator new(size_t n){
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}

inline void operator delete(void *){}
*/

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef unsigned int uint;

ll sqr(ll x){
    return x * x;
}

int mysqrt(ll x){
    int l = 0, r = 1e9 + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (m * (ll)m <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

#ifdef ONPC
    mt19937 rnd(231);
    mt19937_64 rndll(231);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

int gcdex(int a, int b, int &x, int &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int ret = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ret;
}

const int Mod = 998244353;

int Bpow(int x, ll y){
    int ret = 1;
    int w = x;
    while (y){
        if (y & 1)
            ret = (ret * (ll)w) % Mod;
        w = (w * (ll)w) % Mod;
        y >>= 1;
    }
    return ret;
}

int Bdiv(int x){
    int a, b;
    gcdex(x, Mod, a, b);
    if (a < 0)
        a += Mod;
    return a;
}

int Bdiv(int x, int y){
    return (x * (ll)Bpow(y, Mod - 2)) % Mod;
}

inline int ad(int x, int y){
    return x + y >= Mod ? x + y - Mod : x + y;
}

inline int dif(int x, int y){
    return x - y < 0 ? x - y + Mod : x - y;
}

inline int mul(int x, int y){
    return (x * (ll)y) % Mod;
}

int inv(int a){
    int b = Mod, x = 0, y = 1;
    while (a){
        int t = b / a;
        b -= a * t;
        x -= t * y;
        swap(a, b);
        swap(x, y);
    }
    if (x < 0)
        x += Mod;
    return x;
}

void setmin(int &x, int y){
    x = min(x, y);
}

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = min(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

const ll llinf = 4e18 + 100;

const ld eps = 1e-9;

const int maxn = 2e3 + 10, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 600, X = 43, mod = 1e9 + 7, LG = 17;

int n;

int vsdp[maxn];

int fix[maxn];

int f[maxn];

struct fenwick {

    int fen[maxn];

    void inc(int i, int w) {
        for (; i < n; i = (i | (i + 1)))
            fen[i] += w;
    }

    fenwick() {
        for (int i = 0; i < n; i++)
            fen[i] = 0;
        for (int i = 0; i < n; i++) {
            fen[i]++;
            int j = (i | (i + 1));
            if (j < n)
                fen[j] += fen[i];
        }
    }
    void init() {
        for (int i = 0; i < n; i++)
            fen[i] = 0;
        for (int i = 0; i < n; i++) {
            fen[i]++;
            int j = (i | (i + 1));
            if (j < n)
                fen[j] += fen[i];
        }
    }

    int get(int i) {
        int w = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            w += fen[i];
        return w;
    }
};

int d[maxn][maxn];

int gr[maxn];

int mas[maxn], em[maxn], vis[maxn];

fenwick a, b;

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("gymnasts.in");
    //ofstream cout("gymnasts.out");
    //freopen("nextpartition.in", "r", stdin);
    //freopen("nextpartition.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vsdp[1] = 0;
    vsdp[2] = 1;
    for (int i = 3; i <= n; i++)
        vsdp[i] = mul(i - 1, ad(vsdp[i - 1], vsdp[i - 2]));
    fix[0] = 1;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        fix[i] = mul(fix[i - 1], vsdp[n]),
        f[i] = mul(f[i - 1], i);
    d[0][0] = 1;
    for (int s = 1; s <= n; s++)
    for (int x = 0; x <= s; x++) {
        int y = s - x;
        if (y == 0)
            d[s][x] = f[x];
        else
            d[s][x] = ad(mul(x, d[s - 1][x]), (y > 1 ? mul(y - 1, d[s - 1][x + 1]) : 0));
    }
    int ans = 0;
    for (int its = 0; its < n; its++) {
        if (its == 0) {
            fenwick q;
            int w = 0;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                x--;
                gr[i] = x;
                w = ad(w, mul(f[n - 1 - i], q.get(x - 1)));
                q.inc(x, -1);
            }
            ans = ad(ans, mul(w, fix[n - 1 - its]));
            continue;
        }
        a.init();
        b.init();
        for (int i = 0; i < n; i++)
            em[i] = 1, vis[i] = 1;
        int cnt = n;
        int W = 0;
        for (int i = 0; i < n; i++) {
            int now;
            cin >> now;
            now--;
            if (em[gr[i]])
                a.inc(gr[i], -1), em[gr[i]] = 0, cnt--;
            b.inc(now, -1);
            vis[now] = 0;
            int all = b.get(now - 1), to = a.get(now - 1);
            if (vis[gr[i]] && gr[i] < now)
                all--;
            W = ad(W, ad(mul(to, d[n - 1 - i][n - 1 - i - (cnt - 1)]), mul(all - to, d[n - 1 - i][n - 1 - i - cnt])));
            if (em[now])
                a.inc(now, -1), em[now] = 0, cnt--;
            gr[i] = now;
        }
        ans = ad(ans, mul(W, fix[n - 1 - its]));
    }
    cout << ans;
}