#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 998244353 
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    ll a[n];
    ll b[n];
    ll c[n];
    ForA1(n)
    {
    	cin>>a[i];
    	a[i] *= ((i+1)*(n-i));
    }
    ForA1(n)
    {
    	cin>>b[i];
    }


    sort(b,b+n);
    sort(a,a+n);

	ll ans = 0;
	//ll x;
	ForA1(n)
    {
    	ans+= (a[i]%mod)*(b[n-1-i]%mod);
    	/*x%=mod;
    	x*=c[n-i-1];
    	x%=mod;
    	ans+=x;*/
    	ans%=mod;
    }    

    cout<<ans<<endl;

    return 0;
}