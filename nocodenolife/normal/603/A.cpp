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

#define modder 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define F first
#define S second
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    ll answer=1;
    char c = s[0];
    ForA1(s.length())
    {
        if(s[i]==c)
            continue;
        else
        {
            answer++;
            if(c=='1')
                c='0';
            else
                c='1';
        }
    }
    
    answer = min(answer+2,n);
    
    cout<<answer<<endl;
    return 0;
}