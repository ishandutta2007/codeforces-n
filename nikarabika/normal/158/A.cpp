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

typedef unsigned long long int  ull;
typedef long long int           ll;
typedef short int               si;

int main()
{_
    si n, k;
    cin>>n>>k;
    si a[n];
    ull re=0;
    rep(i, n)
        cin>>a[i];
    rep(i, n)
        if(a[i]>=a[k-1] && a[i]>0)
            re++;
    cout<<re<<endl;
    ep;
}