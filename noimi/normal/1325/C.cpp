 #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
#define INF INT_MAX
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}


    
void go();

main(){
    ios
    int tc=1;
    // tc=in();
    while(tc--){
        go();
    }
    return 0;
}

vector<vecpii> g;
void go(){
    int n=in();
    g.resize(n);
    rep(i,n-1){
        int a=in()-1,b=in()-1;
        g[a].eb(b,i);g[b].eb(a,i);
    }
    if(n<=3){
        rep(i,n-1){
            cout<<i<<endl;
        }
    }
    else{
        int t=-1;
        rep(i,n)if(g[i].size()>=3)t=i;
        if(t==-1){
            rep(i,n-1)cout<<i<<endl;
        }
        else{
            vec ans(n,-1);
            int c=3;
            rep(i,3){
                ans[g[t][i].se]=i;
            }
            rep(i,n-1){
                if(ans[i]!=-1)cout<<ans[i]<<endl;
                else cout<<c++<<endl;
            }
        }
    }

}