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

typedef unsigned long long ull;

typedef long double ld;

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR);
    XR = YR;
    YR = ZR;
    return ZR;
}

ll sqr(ll x){
    return x * x;
}

int md(int x, int mymod){
    if (x >= mymod)
        x -= mymod;
    if (x < 0)
        x += mymod;
    return x;
}

vector<int> sufarray(string &s){
    s.push_back('$');
    int n = s.length(), sum;
    vector<int> mas(n), buck(max(n, 256)), col(n), buf(n);
    for (int i = 0; i < n; i++)
        col[i] = s[i];
    fill(buck.begin(), buck.end(), 0);
    sum = 0;
    for (int i = 0; i < n; i++)
        buck[col[i]]++;
    for (int i = 0; i < buck.size(); i++)
        sum += buck[i], buck[i] = sum - buck[i];
    for (int i = 0; i < n; i++)
        mas[buck[col[i]]++] = i;
    col[mas[0]] = 0;
    for (int i = 1; i < n; i++)
        if (s[mas[i]] == s[mas[i - 1]])
            col[mas[i]] = col[mas[i - 1]];
        else
            col[mas[i]] = col[mas[i - 1]] + 1;
    for (int len = 1; len < n; len <<= 1){
        fill(buck.begin(), buck.end(), 0);
        sum = 0;
        for (int i = 0; i < n; i++)
            buck[col[i]]++;
        for (int i = 0; i < n; i++)
            sum += buck[i], buck[i] = sum - buck[i];
        for (int i = 0; i < n; i++)
            buf[buck[col[md(mas[i] - len, n)]]++] = md(mas[i] - len, n);
        mas = buf;
        buf[mas[0]] = 0;
        for (int i = 1; i < n; i++)
            if (col[mas[i]] == col[mas[i - 1]] && col[md(mas[i] + len, n)] == col[md(mas[i - 1] + len, n)])
                buf[mas[i]] = buf[mas[i - 1]];
            else
                buf[mas[i]] = buf[mas[i - 1]] + 1;
        col = buf;
    }
    s.pop_back();
    for (int i = 0; i < n; i++)
        if (mas[i] == n - 1){
            mas.erase(mas.begin() + i);
            break;
        }
    return mas;
}

vector<int> lcpsufarray(vector<int> &sufmas, string &s){
    int n = s.length();
    vector<int> obr(n), mas(n);
    for (int i = 0; i < n; i++)
        obr[sufmas[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++)
        if (obr[i] == n - 1)
            mas[n - 1] = -1;
        else{
            while (max(i + k, sufmas[obr[i] + 1] + k) < n && s[i + k] == s[sufmas[obr[i] + 1] + k])
                k++;
            mas[obr[i]] = k;
            if (k > 0)
                k--;
        }
    return mas;
}

int gcd(int x, int y){
    if (x == 0 || y == 0)
        return max(1, max(x, y));
    return __gcd(x, y);
}

ll lcm(ll x, ll y){
    return x * y / gcd(x, y);
}

pair<int, int> compress(pair<int, int> x){
    if (x.second < 0)
        x.first *= -1, x.second *= -1;
    int g = gcd(abs(x.first), x.second);
    return make_pair(x.first / g, x.second / g);
}

pair<int, int> mkp(int x, int y){
    return make_pair(x, y);
}

int mystoi(string &s){
    int ret = 0;
    int vl = 1;
    if (s[0] == '-')
        vl = -1;
    for (int i = (vl == 1 ? 0 : 1); i < s.length(); i++)
        ret = ret * 10 + s[i] - 48;
    return ret * vl;
}

pair<int, int> operator +(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.second + X.second * Y.first, X.second * Y.second));
}

pair<int, int> operator -(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.second - X.second * Y.first, X.second * Y.second));
}

pair<int, int> operator *(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.first, X.second * Y.second));
}

pair<int, int> operator /(pair<int, int> X, pair<int, int> Y){
    return compress(make_pair(X.first * Y.second, X.second * Y.first));
}

const ll llinf = 4e18 + 100;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 300, mod = 1e9 + 7;

int up[maxn][20];

int s[maxn][20];

int h[maxn];

int n;

pair<int, int> climb(int x, int len){
    int val = 0;
    for (int i = 19; i >= 0; i--)
    if ((1 << i) <= len){
        len -= (1 << i);
        val += s[x][i];
        x = up[x][i];
    }
    return make_pair(x, val);
}

int getlca(int v, int u){
    if (h[v] < h[u])
        swap(v, u);
    v = climb(v, h[v] - h[u]).first;
    if (v == u)
        return v;
    for (int i = 19; i >= 0; i--)
        if (up[v][i] != up[u][i])
            v = up[v][i], u = up[u][i];
    if (up[v][0] != up[u][0])
        return -1;
    return up[v][0];
}

int main() {
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("aplusb.in");
    //ofstream cout("aplusb.out");
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int par, t;
        scanf("%d %d", &par, &t);
        if (par != -1){
            par--;
            h[i] = h[par] + 1;
            up[i][0] = par;
            s[i][0] = t ^ 1;
            for (int j = 1; j < 20; j++)
                up[i][j] = up[up[i][j - 1]][j - 1],
                s[i][j] = s[i][j - 1] + s[up[i][j - 1]][j - 1];
        }
        else{
            for (int j = 0; j < 20; j++)
                up[i][j] = i;
        }
    }
    int zap;
    scanf("%d", &zap);
    for (int i = 0; i < zap; i++){
        int t, v, u;
        scanf("%d %d %d", &t, &v, &u);
        v--;
        u--;
        if (v == u){
            printf("NO\n");
            continue;
        }
        if (t == 1){
            int x = getlca(v, u);
            if (x != v || climb(u, h[u] - h[v]).second != h[u] - h[v])
                printf("NO\n");
            else
                printf("YES\n");
        }
        else{
            int x = getlca(v, u);
            if (x == -1 || x == u || climb(v, h[v] - h[x]).second != h[v] - h[x] || climb(u, h[u] - h[x]).second != 0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}