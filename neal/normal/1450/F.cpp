#include <algorithm>
#include <array>
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
    vector<int> A(N);
    vector<int> freq(N + 1, 0);

    for (auto &a : A) {
        cin >> a;
        freq[a]++;
    }

    if (*max_element(freq.begin(), freq.end()) > (N + 1) / 2) {
        cout << -1 << '\n';
        return;
    }

    vector<int> tail_freq(N + 1, 0);
    vector<vector<int>> paths;
    int start = 0;

    for (int end = 1; end <= N; end++)
        if (end == N || A[end] == A[end - 1]) {
            // path from start to end
            paths.push_back(vector<int>(A.begin() + start, A.begin() + end));
            tail_freq[paths.back().front()]++;
            tail_freq[paths.back().back()]++;
            start = end;
        }

    int P = int(paths.size());
    int most = *max_element(tail_freq.begin(), tail_freq.end());
    int answer = P - 1;
    int extra = max(most - (P + 1), 0);
    answer += extra;
    cout << answer << '\n';
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