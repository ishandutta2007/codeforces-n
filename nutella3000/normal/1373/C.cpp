#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int mod = 998244353;

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int res = 0, Min = 0, num = 0;
        for(int i = 0;i < n;i++) {
            if (s[i] == '+') num++;
            else num--;

            if (num < Min) {
                res += i + 1;
                Min--;
            }
        }
        res += n;
        cout << res << endl;
    }
}