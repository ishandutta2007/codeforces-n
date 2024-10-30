#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int INF = 1e9 + 5;

void run_case() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> ones(N + 1, 0);

    for (int i = 0; i < N; i++)
        ones[i + 1] = ones[i] + (S[i] == '1');

    int answer = ones[N];
    vector<int> dp(N, INF);

    for (int i = 0; i < N; i++) {
        dp[i] = (S[i] != '1') + ones[i];

        if (i >= K)
            dp[i] = min(dp[i], (S[i] != '1') + dp[i - K] + (ones[i] - ones[i - K + 1]));

        answer = min(answer, dp[i] + (ones[N] - ones[i + 1]));
    }

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