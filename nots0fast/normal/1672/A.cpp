#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define ll long long
#define lll __int128
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = pow(10,9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;

void deal(){
      ll t;
      cin>>t;
      forl(t){
            ll n;
            cin>>n;
            ll s = 0;
            fori(n){
                  ll ed;
                  cin>>ed;
                  s+=ed - 1;
            }
            if(s%2 == 0){
                  cout<<"maomao90\n";
            }
            else{
                  cout<<"errorgorn\n";
            }
      }
}

int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}