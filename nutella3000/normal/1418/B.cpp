#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef double ld;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), l(n);
        multiset<int> b;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n;i++) {
            cin >> l[i];
            if (l[i] == 0) 
                b.emplace(a[i]);
        }

        for(int i = 0;i < n;i++) {
            if (l[i] == 0) {
                //cout << b.size() << endl;
                a[i] = *(--b.end());
                b.erase(--b.end());
            }
        }

        for(int i : a)
            cout << i << " ";

        cout << endl;
    }
}