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

const int maxn = 2e5 + 100, maxw = 1e7 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 993, mod1 = 1e9 + 933, LG = 17;

typedef pair<pair<int, int>, int> para;

int n;

para a[maxn];

int ans[maxn];

bool cmp(para x, para y){
    return x.first.first * y.first.second < x.first.second * y.first.first;
}

bool eq(para x, para y){
    return x.first.first * y.first.second == x.first.second * y.first.first;
}

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
    cin >> n;
    for (int i = 0; i < n; i++){
        a[i].second = i;
        string s;
        cin >> s;
        int v = 0;
        int it = 1;
        while (s[it] != '+')
            v = v * 10 + s[it] - 48, it++;
        a[i].first.first += v;
        v = 0;
        it++;
        while (s[it] != ')')
            v = v * 10 + s[it] - 48, it++;
        a[i].first.first += v;
        it += 2;
        v = 0;
        while (it < s.size())
            v = v * 10 + s[it] - 48, it++;
        a[i].first.second = v;
    }
    sort(a, a + n, cmp);
    int it = 0;
    while (it < n){
        int last = it;
        while (it < n && eq(a[it], a[last]))
            it++;
        for (int i = last; i < it; i++)
            ans[a[i].second] = it - last;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}