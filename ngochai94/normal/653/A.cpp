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

int n,lis[55];
set<int> s;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n)
    {
        int val;
        cin>>val;
        s.insert(val);
    }
    n=0;
    for(int i:s)
    {
        lis[n]=i;
        n++;
    }
    For(i,0,n-2) if(lis[i]==lis[i+1]-1&&lis[i]==lis[i+2]-2)
    {
        cout<<"YES"; return 0;
    }
    cout<<"NO";
}