#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[2 * n];
    for(int i = 0;i < 2 * n;i++) cin >> a[i];
    sort(a, a + 2 * n);
    if (a[0] == a[2 * n - 1]) cout << -1;
    else{
        for(int i : a) cout << i  << " ";
    }
}