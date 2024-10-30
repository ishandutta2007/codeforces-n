/*

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

using namespace std;

typedef long long ll;

typedef long double ld;

typedef vector<vector<ll> > matrix;

matrix mul(matrix a, matrix b){
    matrix c;
    c.resize(a.size());
    for (int i = 0; i < c.size(); i++)
        c[i].resize(b[0].size(), 0);
    for (int i = 0; i < c.size(); i++)
        for (int j = 0; j < c[i].size(); j++)
            for (int k = 0; k < b.size(); k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
    return c;
}

matrix Def;

matrix bpow(matrix a, ll st){
    if (st == 0)
        return Def;
    if (st == 1)
        return a;
    matrix b = bpow(a, st >> 1);
    b = mul(b, b);
    if (st & 1)
        b = mul(a, b);
    return b;
}

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
}

ll sqr(ll x){
    return x * x;
}

const ll llinf = 2e18;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 100;

ll q[maxn][4];

pair<int, int> p[maxn][4];

int n;

int a[maxn];

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    for (int j = 0; j < 4; j++)
        q[i][j] = -llinf;
    for (int i = 0; i <= n; i++)
    for (int j = 0; j < 4; j++){
        if (j != 3)
            if (q[i][j + 1] <= q[i][j])
                q[i][j + 1] = q[i][j], p[i][j + 1] = make_pair(i, j);
        if (q[i + 1][j] <= q[i][j] + a[i] * ((j & 1) ? -1 : 1))
            q[i + 1][j] = max(q[i + 1][j], q[i][j] + a[i] * ((j & 1) ? -1 : 1)), p[i + 1][j] = make_pair(i, j);
    }
    int i = n, j = 3;
    vector<int> ans;
    while (i != 0 || j != 0){
        int ni = p[i][j].first, nj = p[i][j].second;
        if (nj < j)
            ans.push_back(i);
        i = ni;
        j = nj;
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << ' ';
}