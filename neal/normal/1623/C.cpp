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
    cin >> N;
    vector<int64_t> H(N);

    for (auto &h : H)
        cin >> h;

    auto possible = [&](int64_t goal) -> bool {
        vector<int64_t> S = H;

        for (int i = N - 1; i >= 0; i--) {
            if (S[i] < goal)
                return false;

            int64_t extra = min(S[i] - goal, H[i]);
            int64_t move = extra / 3;

            if (i >= 2) {
                S[i] -= 3 * move;
                S[i - 1] += move;
                S[i - 2] += 2 * move;
            }
        }

        dbg(goal, S);
        return true;
    };

    int64_t low = 0, high = *max_element(H.begin(), H.end());

    while (low < high) {
        int64_t mid = low + (high - low + 1) / 2;

        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << '\n';
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