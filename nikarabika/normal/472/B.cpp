#include <bits/stdc++.h>

using namespace std;

#define     _               std::ios_base::Init i; std::ios_base::sync_with_stdio(false); std::cin.tie(0);
#define     All(a)          a.begin(), a.end()
#define     FOR(i, s, e)    for(ll i=s; i<=e; i++)
#define     rep(i, t)       for(ll i=0; i<t; i++)
#define     sp              system("pause")
#define     ep              return 0
#define     cendl           cout<<endl
#define     pb              push_back
#define     pob             pop_back
#define     mp              make_pair
#define     p1              first
#define     L               first
#define     p2              second
#define     R               second

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    int n, k;
    int result=0;
    cin>>n>>k;
    int f[n];
    rep(i, n)
        cin>>f[i];
    sort(f, f+n);
    for(int i=n-1; i>=0; i=max(-1, i-k))
    {
        result+=(f[i]-1)*2;
    }
    cout<<result<<endl;
    ep;
}