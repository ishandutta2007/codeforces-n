#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,k,room[100005],r,l,john,ans;
string s;

int f(int x)
{
    return max(abs(room[r]-room[x]),abs(room[x]-room[l]));
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>k>>s;
    n=0;
    For(i,0,s.size()) if(s[i]=='0')
    {
        room[n]=i;
        n++;
    }
    l=0;r=k;john=0;
    ans=mod;
    while(john<n-1&&f(john+1)<=f(john)) john++;
    ans=f(john);
    while(r<n-1)
    {
        l++;r++;
        while(john<n-1&&f(john+1)<=f(john)) john++;
        ans=min(ans,f(john));
    }
    cout<<ans;
}