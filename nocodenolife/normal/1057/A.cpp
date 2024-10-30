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

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i=1;i<n;i++)
    {
        cin>>arr[i];
    }
    ll index = n;
    stack<ll> st;
    st.push(n);
    while(index!=1)
    {
        st.push(arr[index-1]);
        index = arr[index-1];
    }
    
    while(!st.empty())
    {
        index = st.top();
        st.pop();
        cout<<index<<" ";
    }
    cout<<endl;
    return 0;
}