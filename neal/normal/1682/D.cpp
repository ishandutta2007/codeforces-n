#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N;
    string S;
    cin >> N >> S;
    int ones = int(count(S.begin(), S.end(), '1'));

    if (ones == 0 || ones % 2 != 0) {
        cout << "NO" << '\n';
        return;
    }

    vector<pair<int, int>> chains;
    vector<array<int, 2>> edges;

    for (int i = 0; i < N; i++)
        if (S[i] == '1') {
            int x = i;

            while (S[(x + 1) % N] == '0') {
                int y = (x + 1) % N;
                edges.push_back({x, y});
                x = y;
            }

            chains.emplace_back(i, x);
        }

    int C = int(chains.size());

    for (int i = 1; i < C; i++)
        edges.push_back({chains[0].second, chains[i].second});

    cout << "YES" << '\n';

    for (auto &e : edges)
        cout << e[0] + 1 << ' ' << e[1] + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}