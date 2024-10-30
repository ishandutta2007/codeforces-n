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
// #define INF 100000000
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}




int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int t=in();
    while(t--){
        int n=in();
        vec a;
        rep(i,n)a.pb(in());
        if(a==vec(n,a[0])){
            cout<<1<<endl;
            rep(i,n)cout<<1<<" ";
            cout<<endl;continue;
        }
        vec ans;
        ans.pb(1);
        int pre=1;
        rep(i,n-1){
            if(a[i]==a[i+1])ans.pb(pre);
            else ans.pb(3-pre),pre=3-pre;
        }
        if(a[0]!=a[n-1] and pre==1){
            bool f=false;
            int pre=1;
            rep(i,n-1){
                if(!f and a[i]==a[i+1]){
                    f=true;
                    ans[i+1]=3-pre;
                    pre=3-pre;
                }
                else if(a[i]==a[i+1])ans[i+1]=pre;
                else pre=3-pre,ans[i+1]=pre;
            }
            if(!f)
            ans.back()=3;
        }
        if(ans.back()==3){
            cout<<3<<endl;
            print(ans);
        }
        else {
            cout<<2<<endl;
            print(ans);
        }
    }
}