#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,l,r; cin>>n>>l>>r;
    int mi=0,ma=0;
    int cnt=1;
    loop(i,0,n){
        if (i+1<r){
            ma+=cnt;
            cnt*=2;
        }
        else ma+=cnt;
    }
    cnt=1;
    loop(i,0,n){
        if (i<n-l) mi+=cnt;
        else {
            mi+=cnt;
            cnt*=2;
        }
    }
    cout << mi << " " << ma <<endl;

    return 0;
}