#include<bits/stdc++.h>
using namespace std;
#define int long long
main () {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        while(n)
        ans=max(ans,n%10),n/=10;
        cout<<ans<<endl;
    }
}