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
    vector<string> A(N), B(N);
    vector<string> diff(N);

    for (auto &row : A)
        cin >> row;

    for (auto &row : B)
        cin >> row;

    for (int i = 0; i < N; i++) {
        string str;

        for (int j = 0; j < N; j++)
            str += A[i][j] == B[i][j] ? '0' : '1';

        diff[i] = str;
    }

    for (int i = 1; i < N; i++) {
        bool same = true, opposite = true;

        for (int j = 0; j < N; j++) {
            same = same && diff[i][j] == diff[0][j];
            opposite = opposite && diff[i][j] != diff[0][j];
        }

        if (!same && !opposite) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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