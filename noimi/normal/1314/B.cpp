// #pragma GCC optimize("O3")
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
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}



vec a;
vec solve(int x,int y){
    if(x==y-2){
        int cnt=a[x]+a[x+1];
        if(cnt==1) return {0,1,1,0};
        else if(cnt==2) return {0,0,0,1};
        else return {0,0,0,0};
    }
    vec t=solve(x,(x+y)/2),s=solve((x+y)/2,y),res(4);
    rep(i,4){
        rep(j,4){
            int tmp=t[i]+s[j];
            int a1=i&1,a2=j&1;
            int b1=((i&2)>0),b2=((j&2)>0);
            if((t[i]==0 and i!=0) or (s[j]==0 and j!=0))continue;
            if(b1==0 and b2==0 and (a1^a2)){ chmax(res[2],tmp+2); }
            int s=0;
            if(a1 or a2){ s++;tmp++; }
            if(b1 or b2){ s+=2;tmp+=2; }
            chmax(res[s],tmp);
        }
    }
    return res;
}
main(){
    ios
    int n=in(),k=in();
    int N=1<<n;
    a.resize(N);
    rep(i,k)a[in()-1]=1;
    vec ans=solve(0,N);
    cout<<*max_element(all(ans))+(k>0)<<endl;
    
}