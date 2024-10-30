#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    string S;
    int X;
    cin >> S >> X;
    int N = int(S.size());
    string W(N, '1');

    for (int i = 0; i < N; i++)
        if (S[i] == '0') {
            if (i - X >= 0)
                W[i - X] = '0';

            if (i + X < N)
                W[i + X] = '0';
        }

    for (int i = 0; i < N; i++) {
        bool one = false;
        one = one || (i - X >= 0 && W[i - X] == '1');
        one = one || (i + X < N && W[i + X] == '1');

        if (S[i] != one + '0') {
            cout << -1 << '\n';
            return;
        }
    }

    cout << W << '\n';
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