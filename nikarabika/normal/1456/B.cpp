//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

//#define COMB_TRIPLE
//const int maxcomb = 1000 * 1000 + 100;
//#define COMB_DP
//const int maxcomb = 5000 + 10;

const LL Mod = 1000 * 1000 * 1000 + 7;
//const LL Mod = 998244353;

template <typename T, T fenmod = 0>
struct BIT{
    T *fen;
    int size;

    BIT(int size) { fen = new T[size + 1], this->size = size; }

    void inc(int idx, T val) {
        for (idx++; idx <= size; idx += idx & -idx) {
            fen[idx] += val;
            if (fenmod) fen[idx] %= fenmod;
        }
    }

    T get(int idx) {
        T sum = 0;
        for (; idx; idx -= idx & -idx) {
            sum += fen[idx];
            if (fenmod) sum %= fenmod;
        }
        return sum;
    }

    T get(int st, int en) { return get(en) - get(st); }
};

// Segment Tree
struct SegmentTree {
    int *seg;
    int segL, segR;

    SegmentTree(int segl, int segr) {
        segL = segl;
        segR = segr;
        seg = new int[(segr - segl) << 2];
    }

    int build(int l, int r, int id) {
        if (r - l == 1) {
            seg[id] = l;
            return seg[id];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        res += build(l, mid, id << 1 | 0);
        res += build(mid, r, id << 1 | 1);
        seg[id] = res;
        return res;
    }
    int build() {
        return build(segL, segR, 1);
    }

    int pointQuery(int idx, int val, int l, int r, int id) {
        if (idx < l or r <= idx)
            return 0;
        if (r - l == 1) {
            seg[id] = val;
            return seg[id];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        res += pointQuery(idx, val, l, mid, id << 1 | 0);
        res += pointQuery(idx, val, mid, r, id << 1 | 1);
        return res;
    }
    int pointQuery(int idx, int val) { return pointQuery(idx, val, segL, segR, 1); }

    int segQuery(int st, int en, int val, int l, int r, int id) {
        if (st >= r or en <= l)
            return 0;
        if (st <= l and r <= en)
            return seg[id];
        int mid = (l + r) >> 1;
        int res = 0;
        res += segQuery(st, en, val, l, mid, id << 1 | 0);
        res += segQuery(st, en, val, mid, r, id << 1 | 1);
        return res;
    }
    int segQuery(int st, int en, int val) { return segQuery(st, en, val, segL, segR, 1); }
};

class SuffixStructure {
    string s;
    int *sa;
    int *pos;
    int *lcp;

    int tn;
    int *par;
    int *h;
    vector<pair<int, pii>> *adj;

    SuffixStructure(string str) {
        s = str + "$";
    }

    void build_sa() {
        int n = sz(s);
        sa = new int[n];
        pos = new int[n];
        for (int i = 0; i < n; i++)
            sa[i] = i, pos[i] = s[i];
        int gap;
        auto cmp = [&](int i, int j) -> bool {
            if (pos[i] != pos[j]) return pos[i] < pos[j];
            i += gap, j += gap;
            return (i < n and j < n) ? pos[i] < pos[j] : i > j;
        };
        for (gap = 1; ; gap <<= 1) {
            sort(sa, sa + n, cmp);
            int tmp = 0;
            pos[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp += cmp(sa[i - 1], sa[i]);
                pos[sa[i]] = tmp;
            }
            if (tmp == n - 1) break;
        }
    }

    void build_lcp() {
        int n = sz(s);
        lcp = new int[n];
        for (int i = 0, cur = 0; i < n; i++) {
            if (int j = pos[i] + 1; j < n) {
                while (max(i, j) + cur < n and s[i + cur] == s[j + cur])
                    cur++;
                lcp[pos[i] + 1] = cur;
            }
            if (cur) cur--;
        }
    }

    void build_tree() {
        int n = sz(s);
        tn = 2 * n - 1;
        adj = new vector<pair<int, pii>>[tn];
        par = new int[tn];
        h = new int[tn];
        memset(par, -1, tn * sizeof(int));
        memset(h, 0, tn * sizeof(int));
        stack<pair<int, pii>> stc;
        int verts = n;
        stc.push(MP(verts, pii(0, 0)));
        verts++;
        auto seg_break = [](pii seg, int len) {
            pii le = seg,
                ri = seg;
            le.R = le.L + len;
            ri.L = le.R;
            return MP(le, ri);
        };
        for (int i = 0; i < n; i++) {
            while (h[stc.top().L] > lcp[i]) {
                auto top = stc.top();
                stc.pop();
                if (h[stc.top().L] < lcp[i]) {
                    pair<pii, pii> brk = seg_break(top.R, lcp[i] - h[stc.top().L]);
                    stc.push(MP(verts, brk.L));
                    h[verts] = lcp[i];
                    verts++;

                    top.R = brk.R;
                }
                par[top.L] = stc.top().L;
                adj[stc.top().L].PB(top);
            }
            h[i] = n - sa[i];
            stc.push(MP(i, pii(i + h[stc.top().L], n)));
        }
        while (h[stc.top().L] > 0) {
            auto top = stc.top();
            stc.pop();
            par[top.L] = stc.top().L;
            adj[stc.top().L].PB(top);
        }
    }
};

LL Pow(LL x, LL y) {
    LL ans = 1,
       an = x % Mod;
    while (y) {
        if (y & 1LL)
            ans = ans * an % Mod;
        an = an * an % Mod;
        y >>= 1;
    }
    return ans;
}

LL Inv(LL x) { return Pow(x, Mod - 2); }

#ifdef COMB_TRIPLE
LL fact[maxcomb];
LL fact_inv[maxcomb];
LL comb(LL n, LL r) {
    static bool comped = false;
    if (!comped) {
        fact[0] = fact_inv[0] = 1;
        for (int i = 1; i < maxcomb; i++) {
            fact[i] = fact[i - 1] * i % Mod;
            fact_inv[i] = Inv(fact[i]);
        }
        comped = true;
    }
    if (r < 0 or r > n) return 0;
    return (fact[n] * fact_inv[r] % Mod) * fact_inv[n - r] % Mod;
}
#elif defined(COMB_DP)
LL comb_array[maxcomb][maxcomb];
LL comb(LL n, LL r) {
    static bool comped = false;
    if (!comped) {
        comb_array[0][0] = 1;
        for (int i = 1; i < maxcomb; i++) {
            comb_array[i][0] = 1;
            for (int j = 1; j <= i; j++)
                comb_array[i][j] = (comb_array[i - 1][j - 1] + comb_array[i - 1][j]) % Mod;
        }
        comped = true;
    }
    if (r < 0 or r > n) return 0;
    return comb_array[n][r];
}
#endif

int solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
    q = 1;
	while (q--)
		solve();
	return 0;
}

const int maxn = 100 * 1001,
      maxl = 32;
LL a[maxn],
   sum[maxn],
   pre[maxn][maxl],
   n;
vector<int> vec[maxl][maxn];
vector<LL> all[maxl];

int solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[n - 1 - i];
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] ^ a[i];
//    for (int i = 0; i <= n; i++)
//        cerr << a[i] << ' ';
//    cerr << '\n';
//    for (int i = 0; i <= n; i++)
//        cerr << sum[i] << ' ';
//    cerr << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < maxl; j++)
            if (((sum[i] >> j) & 1) == (1 & (sum[i - 1] >> j)))
                pre[i][j] = pre[i - 1][j];
            else
                pre[i][j] = i;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < maxl; j++)
            all[j].PB(sum[i] >> j);
    for (int i = 0; i < maxl; i++) {
        sort(all(all[i]));
        all[i].resize(unique(all(all[i])) - all[i].begin());
//        cerr << i << ": ";
//        for (auto num: all[i])
//            cerr << num << ' ';
//        cerr << '\n';
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < maxl; j++) {
            LL val = sum[i] >> j;
            int id = lower_bound(all(all[j]), val) - all[j].begin();
            vec[j][id].PB(i);
        }
    int ans = n + n;
    for (int r = 2; r <= n; r++) {
        for (int bit = 0; bit < maxl; bit++) {
            int pos = pre[r][bit];
            LL val = ((sum[r] >> bit) ^ 1LL);
            int id = lower_bound(all(all[bit]), val) - all[bit].begin();
            if (all[bit][id] != val) continue;
            auto it = lower_bound(all(vec[bit][id]), pos - 1);
            if (it != vec[bit][id].begin()) {
                it--;
//                cerr << "HI" << ' ' << r << ' ' << bit << ' ' << *it << ' ' << (r - (*it) - 2) << endl;
//                cerr << "#" << pos << ' ' << val << ' ' << id << '\n';
//                for (auto x: vec[bit][id])
//                    cerr << "! " << x << '\n';
//                cerr << endl;
//                cerr << ans << endl;
                smin(ans, r - (*it) - 2);
//                cerr << ans << endl;
//                cerr << endl;
            }
        }
    }
    if (ans >= n)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}