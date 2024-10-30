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
#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

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

mt19937 rnd(1227);

mt19937_64 rndll(12365);

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

const int Mod = 1e9 + 7;

int bpow(int x, int y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int ret = bpow(x, y >> 1);
    ret = (ret * (ll)ret) % Mod;
    if (y & 1)
        ret = (ret * (ll)x) % Mod;
    return ret;
}

int bdiv(int x, int y){
    return (x * (ll)bpow(y, Mod - 2)) % Mod;
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

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

const ll llinf = 2e18 + 100;

const double eps = 1e-9;

const int maxn = 3e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 993, LG = 17;

int n;

int w[2];

pair<int, int> a[maxn];

int q[maxn][2];

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
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w[0] >> w[1];
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    for (int i = 0; i < n; i++)
        q[i][0] = n + 1, q[i][1] = n + 1;
    sort(a, a + n);
    for (int t = 0; t < 2; t++){
        for (int i = 1; i <= n; i++){
            int l = -1, r = n;
            while (r - l > 1){
                int m = (l + r) / 2;
                if (a[m].first * (ll)i >= w[t])
                    r = m;
                else
                    l = m;
            }
            setmin(q[r][t], i);
        }
    }
    int x = n + 1;
    for (int i = n - 1; i >= 0; i--){
        if (n - i >= q[i][0])
            setmin(x, q[i][0]);
        if (x + q[i][1] <= n - i){
            cout << "Yes\n" << x << ' ' << q[i][1] << '\n';
            for (int j = 1; j <= x; j++)
                cout << a[n - j].second + 1 << ' ';
            cout << '\n';
            for (int j = 1; j <= q[i][1]; j++)
                cout << a[n - x - j].second + 1 << ' ';
            return 0;
        }
    }
    x = n + 1;
    for (int i = n - 1; i >= 0; i--){
        if (n - i >= q[i][1])
            setmin(x, q[i][1]);
        if (x + q[i][0] <= n - i){
            cout << "Yes\n" << q[i][0] << ' ' << x << '\n';
            for (int j = 1; j <= q[i][0]; j++)
                cout << a[n - x - j].second + 1 << ' ';
            cout << '\n';
            for (int j = 1; j <= x; j++)
                cout << a[n - j].second + 1 << ' ';
            return 0;
        }
    }
    cout << "No";
}