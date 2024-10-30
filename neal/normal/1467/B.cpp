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

    for (auto &a : A)
        cin >> a;

    auto score = [&](int index) {
        if (index <= 0 || index >= N - 1)
            return 0;

        if (A[index] < A[index - 1] && A[index] < A[index + 1])
            return 1;

        if (A[index] > A[index - 1] && A[index] > A[index + 1])
            return 1;

        return 0;
    };

    int base = 0;

    for (int i = 0; i < N; i++)
        base += score(i);

    int best = base;

    for (int i = 0; i < N; i++) {
        int original = A[i];
        set<int> candidates;

        if (i > 0)
            candidates.insert(A[i - 1]);

        if (i < N - 1)
            candidates.insert(A[i + 1]);

        int without = base - score(i - 1) - score(i) - score(i + 1);

        for (int x : candidates) {
            A[i] = x;
            best = min(best, without + score(i - 1) + score(i) + score(i + 1));
        }

        A[i] = original;
    }

    cout << best << '\n';
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