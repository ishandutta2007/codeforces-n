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

mt19937 rnd(1337);

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

const ll llinf = 2e18 + 100;

const int maxn = 2e5 + 100, maxw = (1 << 20) + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int n;

vector<int> e[maxn];

bool vis[maxn];

int sz[maxn];

int q[maxw];

int arr[maxn];

ll ans[maxn];

void calcsz(int v, int par){
    sz[v] = 1;
    for (auto i : e[v])
    if (i != par && !vis[i])
        calcsz(i, v), sz[v] += sz[i];
}

int getcd(int v, int par, int SZ){
    for (auto i : e[v])
    if (i != par && !vis[i] && sz[i] * 2 >= SZ)
        return getcd(i, v, SZ);
    return v;
}

void add(int v, int par, int val, int kf){
    val ^= (1 << arr[v]);
    q[val] += kf;
    for (auto i : e[v])
    if (i != par && !vis[i])
        add(i, v, val, kf);
}

ll dfs(int v, int par, int val, int cd){
    val ^= (1 << arr[v]);
    int pep = val ^ cd;
    ll ret = q[pep];
    for (int i = 0; i < 20; i++)
        ret += q[pep ^ (1 << i)];
    for (auto i : e[v])
    if (i != par && !vis[i])
        ret += dfs(i, v, val, cd);
    ans[v] += ret;
    return ret;
}

ll go(int v, int par, int val, int cd){
    val ^= (1 << arr[v]);
    int pep = val ^ cd;
    ll ret = q[pep];
    for (int i = 0; i < 20; i++)
        ret += q[pep ^ (1 << i)];
    for (auto i : e[v])
    if (i != par && !vis[i])
        ret += go(i, v, val, cd);
    return ret;
}

void makecd(int st){
    calcsz(st, -1);
    int cd = getcd(st, -1, sz[st]);
    q[0]++;
    for (auto i : e[cd])
    if (!vis[i])
        ans[cd] += go(i, cd, 0, (1 << arr[cd])), add(i, cd, 0, 1);
    for (auto i : e[cd])
    if (!vis[i]){
        add(i, cd, 0, -1);
        dfs(i, cd, 0, (1 << arr[cd]));
        add(i, cd, 0, 1);
    }
    q[0]--;
    for (auto i : e[cd])
    if (!vis[i])
        add(i, cd, 0, -1);
    vis[cd] = 1;
    for (auto i : e[cd])
    if (!vis[i])
        makecd(i);
}

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("sprinklers.in");
    //ofstream cout("sprinklers.out");
    //freopen("road.in", "r", stdin);
    //freopen("road.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    string ss;
    cin >> ss;
    for (int i = 0; i < n; i++)
        arr[i] = ss[i] - 'a', ans[i] = 1;
    makecd(0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}