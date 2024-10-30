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


const int INF = 1e9 + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<vector<int>> locations(N + 1);

    for (int i = 0; i < N; i++)
        locations[A[i]].push_back(i);

    vector<int> answers(N + 1, INF);

    for (int a = 1; a <= N; a++) {
        locations[a].insert(locations[a].begin(), -1);
        locations[a].push_back(N);
        int biggest = 0;

        for (int i = 0; i < int(locations[a].size()) - 1; i++)
            biggest = max(biggest, locations[a][i + 1] - locations[a][i]);

        if (biggest <= N)
            answers[biggest] = min(answers[biggest], a);
    }

    for (int x = 1; x <= N; x++)
        answers[x] = min(answers[x], answers[x - 1]);

    for (int x = 1; x <= N; x++)
        cout << (answers[x] < INF ? answers[x] : -1) << (x < N ? ' ' : '\n');
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